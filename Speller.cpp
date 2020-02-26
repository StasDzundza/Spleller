//
// Created by STAS on 26.02.2020.
//

#include "Speller.h"
#include "data structures/HashMapFacade.h"
#include "data structures/VectorFacade.h"
#include "data structures/BinaryTree.h"
#include "data structures/ChainHashTable.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

Speller::Speller() {
    checker = new HashMapFacade();
    checker_type = checker->get_type();
}

Speller::Speller(Checker::Type type) {
    switch (type){
        case Checker::Type::STD_VECTOR:
            checker = new VectorFacade();
            break;

        case Checker::Type::STD_UNORDERED_MAP:
            checker = new HashMapFacade();
            break;

        case Checker::Type::BIN_TREE:
            checker = new BinaryTree();
            break;

        case Checker::Type::HASH_TABLE:
            checker = new ChainHashTable();
            break;
    }
    checker_type = checker->get_type();
}

void Speller::check_text(const std::string &path_to_dictionary, const std::string path_to_text, const std::string bad_words_filename) {
    load_dictionary(path_to_dictionary);
    load_text(path_to_text);
    std::ofstream output_file(bad_words_filename);
    for(auto &word:text_words){
        if(!checker->check(word)){
            number_of_bad_words++;
            output_file << word << '\n';
        }
    }
    output_file.close();
}

void Speller::load_dictionary(const std::string& path_to_dictionary) {
    std::ifstream file(path_to_dictionary);
    std::ios::iostate old_exceptions = file.exceptions();
    file.exceptions(std::ios::failbit | std::ios::badbit);
    std::string word;
    try {
        std::string word;
        while (true) {
            std::getline(file, word);
            if (!word.empty()) {
                checker->add(word);
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
}

void Speller::load_text(const std::string &path_to_text) {
    std::ifstream file(path_to_text);
    std::ios::iostate old_exceptions =file.exceptions();
    file.exceptions(std::ios::failbit | std::ios::badbit);
    std::string word;
    try {
        char c;
        while (true) {
            c = file.get();
            if(file.eof()) {
                break;
            }else if (std::isalpha(c) or c == '\'') {
                word += c;
            } else if (!word.empty()) {
                to_lower_case(word);
                text_words.push_back(word);
                number_of_words_in_text++;
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
            text_words.push_back(word);
            number_of_words_in_text++;
            word.clear();
        }
        file.close();
    }
}

void Speller::to_lower_case(std::string &word) {
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
        if (c != '\'')
            return std::tolower(c);
        else
            return (int) c;
    });
}

Speller::~Speller() {
    delete checker;
}







