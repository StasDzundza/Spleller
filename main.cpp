#include <iostream>
#include "Speller.h"

int main() {
    Speller speller(Checker::Type::STD_VECTOR);
    speller.check_text("dict.txt","text.txt","bad_words.txt");
    return 0;
}
