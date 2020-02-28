//
// Created by STAS on 26.02.2020.
//

#include "Speller.h"
#include "data structures/HashMapFacade.h"
#include "data structures/VectorFacade.h"
#include "data structures/BinaryTree.h"
#include "data structures/ChainHashTable.h"
#include "Timer.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>
//#include "boost/filesystem.hpp"

Speller::Speller():checker_type(Checker::Type::STD_UNORDERED_MAP) {
}

Speller::Speller(Checker::Type type):checker_type(type) {
}

Checker *Speller::allocate_checker(Checker::Type type) {
    checker_type = type;
    switch (type){
        case Checker::Type::STD_VECTOR:
            return new VectorFacade();

        case Checker::Type::STD_UNORDERED_MAP:
            return new HashMapFacade();

        case Checker::Type::BIN_TREE:
            return new BinaryTree();

        case Checker::Type::HASH_TABLE:
            return new ChainHashTable();

        default:
            return new HashMapFacade();
    }
}

void Speller::check_text(const std::string &path_to_dictionary, const std::string& path_to_text) {
    load_dictionary(path_to_dictionary);
    load_text(path_to_text);
    std::string bad_words_filename = path_to_text + "_bad_words";
    std::vector<std::string>bad_words;
    number_of_bad_words = 0;
    Timer timer;
    timer.start();
    for(auto &word:text_words){
        if(!checker->check(word)){
            if(!std::binary_search(bad_words.begin(),bad_words.end(),word))
                bad_words.push_back(word);
        }
    }
    number_of_bad_words = bad_words.size();
    checking_time = timer.stop_and_get_result();
    write_bad_words_to_file(bad_words,bad_words_filename);
    delete checker;
}

void Speller::write_bad_words_to_file(const std::vector<std::string>& bad_words, const std::string& bad_words_filename) {
    std::ofstream output_file(bad_words_filename);
    for(auto &word:bad_words)
        output_file << word << '\n';
    output_file.close();
}

void Speller::load_dictionary(const std::string& path_to_dictionary) {
    checker = allocate_checker(checker_type);
    std::ifstream file(path_to_dictionary);
    std::ios::iostate old_exceptions = file.exceptions();
    file.exceptions(std::ios::failbit | std::ios::badbit);
    std::string word;
    std::vector<std::string>dictionary;
    try {
        std::string word;
        while (true) {
            std::getline(file, word);
            if (!word.empty()) {
                //checker->add(word);
                dictionary.push_back(word);
                word.clear();
            } else if(file.eof() or word.empty()){
                break;
            }
        }
    }catch (...){
        if(!file.eof()){
            file.exceptions(old_exceptions);
            throw;
        }
        file.close();
    }
    if(checker_type == Checker::Type::BIN_TREE)
        std::random_shuffle(dictionary.begin(),dictionary.end());
    Timer timer;
    timer.start();
    for(auto&word:dictionary)
        checker->add(word);
    dictionary_loading_time = timer.stop_and_get_result();
}

void Speller::load_text(const std::string& path_to_text) {
    text_words.clear();
    std::ifstream file(path_to_text);
    std::ios::iostate old_exceptions = file.exceptions();
    file.exceptions(std::ios::failbit | std::ios::badbit);
    std::string word;
    try {
        char c;
        while (true) {
            c = file.get();
            if(file.eof()) {
                break;
            }else if (std::isalpha(c)) {
                word += c;
            }else if(c == '\'' and !word.empty()){
                word += '\'';
            }else if (!word.empty()) {
                to_lower_case(word);
                if(word[word.size() - 1] == '\''){
                    word.resize(word.size() - 1);
                }
                text_words.push_back(word);
                word.clear();
            }
        }
    }catch(...){
        if(!file.eof()){
            file.exceptions(old_exceptions);
            throw;
        }
        else if(!word.empty()){
            to_lower_case(word);
            if(word[word.size() - 1] == '\''){
                word.resize(word.size() - 1);
            }
            text_words.push_back(word);
            word.clear();
        }
        file.close();
    }
}

void Speller::to_lower_case(std::string& word) {
    std::transform(word.begin(), word.end(), word.begin(), [](char c) {
        if (c != '\'')
            return std::tolower(c);
        else
            return (int) c;
    });
}

std::string Speller::get_result() {
    return checker->get_name() + ' ' + std::to_string(dictionary_loading_time) +
            ' ' + std::to_string(checking_time) + ' ' + std::to_string(text_words.size()) +
            ' ' + std::to_string(number_of_bad_words);
}

void Speller::check_texts(const std::string &path_to_dictionary, const std::vector<std::string>& filenames,
        bool check_repeats_of_bad_words) {
    /*std::vector<std::string> filenames;
    for(boost::filesystem::recursive_directory_iterator rdib(path_to_dir_with_texts), rdie; rdib != rdie; ++rdib){
        filenames.push_back(rdib->path().filename().string());
    }*/
    std::vector<std::string>bad_words;
    int index = 1;
    for(auto&text_filename:filenames){
        load_text(text_filename);
        std::string bad_words_filename = "bad_words_" + std::to_string(index) + ".txt";
        std::cout << text_filename << std::endl;
        for(int i = 0; i < 4; i++){
            checker_type = (Checker::Type)i;
            load_dictionary(path_to_dictionary);
            Timer timer;
            timer.start();
            for(auto &word:text_words){
                if(!checker->check(word)){
                    if(check_repeats_of_bad_words and std::find(bad_words.begin(),bad_words.end(),word) == bad_words.end())
                        bad_words.push_back(word);
                    else if(!check_repeats_of_bad_words)
                        bad_words.push_back(word);
                }
            }
            checking_time = timer.stop_and_get_result();
            number_of_bad_words = bad_words.size();
            if(i == 3)
               write_bad_words_to_file(bad_words,bad_words_filename);
            std::cout << get_result() << std::endl;
            bad_words.clear();
            number_of_bad_words = 0;
            delete checker;
        }
        index++;
    }
}











