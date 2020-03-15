#include "Speller.h"

int main() {
    std::string dict_path = "../dict/large.txt";
    std::string texts_path = "../texts";
    Speller s;
    s.check_texts(dict_path, texts_path);
    return 0;
}
