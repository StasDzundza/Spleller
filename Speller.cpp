//
// Created by STAS on 26.02.2020.
//

#include "Speller.h"
#include "DataStructures/UnorderedMapWrapper.h"
#include "DataStructures/VectorWrapper.h"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/ChainHashTable.h"
#include "Timer.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace {
    const int NumberOfDataStructures = 4;
}

Speller::Speller():checker_type(Checker::Type::STD_UNORDERED_MAP) {
}

Speller::Speller(Checker::Type type):checker_type(type) {
}

Checker *Speller::allocate_checker(Checker::Type type) {
    checker_type = type;
    switch (type){
        case Checker::Type::STD_VECTOR:
            return new VectorWrapper();

        case Checker::Type::STD_UNORDERED_MAP:
            return new UnorderedMapWrapper();

        case Checker::Type::BIN_TREE:
            return new BinaryTree();

        case Checker::Type::HASH_TABLE:
            return new ChainHashTable();

        default:
            return new UnorderedMapWrapper();
    }
}

void Speller::check_text(const std::string &path_to_dictionary, const std::string& path_to_text) {
    load_dictionary(path_to_dictionary);
    load_text(path_to_text);
    std::string bad_words_filename = path_to_text + "_bad_words";
    std::set<std::string>bad_words;
    number_of_bad_words = 0;
    Timer timer;
    timer.start();
    for(auto &word:text_words){
        if(!checker->check(word)){
            if(std::find(bad_words.begin(),bad_words.end(),word) == bad_words.end()) {
                bad_words.insert(word);
            }
        }
    }
    number_of_bad_words = bad_words.size();
    checking_time = timer.stop_and_get_result();
    write_bad_words_to_file(bad_words,bad_words_filename);
    delete checker;
}

void Speller::write_bad_words_to_file(const std::set<std::string>& bad_words, const std::string& bad_words_filename) {
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
                dictionary.emplace_back(word);
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
                text_words.emplace_back(word);
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
            text_words.emplace_back(word);
            word.clear();
        }
        file.close();
    }
}

void Speller::to_lower_case(std::string& word)const {
    std::transform(word.begin(), word.end(), word.begin(), [](char c) {
        if (c != '\'')
            return std::tolower(c);
        else
            return (int) c;
    });
}

std::string Speller::get_checking_result()const {
    return checker->get_name() + ' ' + std::to_string(dictionary_loading_time) +
            ' ' + std::to_string(checking_time) + ' ' + std::to_string(text_words.size()) +
            ' ' + std::to_string(number_of_bad_words);
}

void Speller::check_texts(const std::string &path_to_dictionary, const std::string& path_to_dir_with_texts) {
    std::vector<std::string> filenames = get_filenames(path_to_dir_with_texts);
    std::set<std::string>bad_words;
    int index = 1;
    for(auto&text_filename:filenames){
        load_text(text_filename);
        std::string bad_words_filename = "bad_words_" + std::to_string(index) + ".txt";
        std::cout << text_filename << std::endl;
        for(int i = 0; i < NumberOfDataStructures; i++){
            checker_type = (Checker::Type)i;
            load_dictionary(path_to_dictionary);
            Timer timer;
            timer.start();
            for(auto &word:text_words){
                if(!checker->check(word)){
                    if(bad_words.find(word) == bad_words.end()) {
                        bad_words.insert(word);
                    }
                }
            }
            checking_time = timer.stop_and_get_result();
            number_of_bad_words = bad_words.size();
            if(i == (NumberOfDataStructures - 1)) {
                write_bad_words_to_file(bad_words, bad_words_filename);
            }
            std::cout << get_checking_result() << std::endl;
            bad_words.clear();
            number_of_bad_words = 0;
            delete checker;
        }
        index++;
    }
}

std::vector<std::string> Speller::get_filenames(const std::string &path_to_directory_with_files) const {
    std::vector<std::string> filenames;
    for (const auto &entry : fs::directory_iterator(path_to_directory_with_files)){
        filenames.emplace_back(entry.path().string());
    }
    return filenames;
}











