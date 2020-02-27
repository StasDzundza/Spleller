#include <iostream>
#include "Speller.h"

int main() {
    Speller *speller = new Speller(Checker::Type::STD_UNORDERED_MAP);
    speller->check_text("../dict/large.txt","../texts/alice.txt","../results/bad_words1.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;

    /*speller = new Speller(Checker::Type::STD_UNORDERED_MAP);
    speller->check_text("../test data/large.txt","../test data/alice.txt","../bad_words2.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;

    speller = new Speller(Checker::Type::HASH_TABLE);
    speller->check_text("../test data/large.txt","../test data/alice.txt","../bad_words3.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;

    speller = new Speller(Checker::Type::BIN_TREE);
    speller->check_text("../test data/large.txt","../test data/alice.txt","../bad_words4.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;*/

    return 0;
}
