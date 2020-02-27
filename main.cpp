#include <iostream>
#include "Speller.h"

int main() {
    std::string dict_path = "../dict/large.txt";

/*    Speller *speller = new Speller(Checker::Type::HASH_TABLE);
    speller->check_text(dict_path,"../texts/alice.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;

    speller = new Speller(Checker::Type::STD_VECTOR);
    speller->check_text(dict_path,"../texts/alice.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;

    speller = new Speller(Checker::Type::STD_UNORDERED_MAP);
    speller->check_text(dict_path,"../texts/alice.txt");
    std::cout << speller->get_result() << std::endl;
    delete speller;*/

    std::vector<std::string>path_to_texts = {"../texts/alice.txt","../texts/dracula.txt","../texts/holmes.txt","../texts/sherlock.txt",
                                            "../texts/tolstoy.txt"};
    Speller s;
    s.check_texts(dict_path,path_to_texts);

    return 0;
}
