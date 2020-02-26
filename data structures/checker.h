//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <string>

class Checker{
public:
    virtual void add(const std::string&value) = 0;
    virtual bool check(const std::string&value)const = 0;
};
#endif //SPELLER_CHECKER_H
