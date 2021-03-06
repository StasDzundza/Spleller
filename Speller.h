//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_SPELLER_H
#define SPELLER_SPELLER_H

#include "DataStructures/checker.h"
#include <vector>
#include <set>

class Speller {
public:
    Speller();

    Speller(Checker::Type type);

    void check_text(const std::string &path_to_dictionary, const std::string &path_to_text);

    void check_texts(const std::string &path_to_dictionary, const std::string &path_to_dir_with_texts);

    std::string get_checking_result() const;

private:
    void load_dictionary(const std::string &path_to_dictionary);

    void load_text(const std::string &path_to_text);

    void to_lower_case(std::string &word) const;

    std::vector<std::string> get_filenames(const std::string &path_to_directory_with_files) const;

    void write_bad_words_to_file(const std::set<std::string> &bad_words, const std::string &bad_words_filename);

    Checker *allocate_checker(Checker::Type type);

    Checker *checker;
    std::vector<std::string> text_words;
    Checker::Type checker_type;
    unsigned long int dictionary_loading_time = 0, checking_time = 0;
    int number_of_bad_words = 0;
};


#endif //SPELLER_SPELLER_H
