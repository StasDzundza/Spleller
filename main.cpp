#include "Speller.h"

int main() {
    std::string dict_path = "../dict/large.txt";
    std::vector<std::string>path_to_texts = {"../texts/alice.txt","../texts/dracula.txt","../texts/holmes.txt","../texts/sherlock.txt",
                                            "../texts/tolstoy.txt"};
    Speller s;
    s.check_texts(dict_path,path_to_texts);
    return 0;
}
