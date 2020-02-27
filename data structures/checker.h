//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <string>
class Checker{
public:
    enum Type{
        BIN_TREE,
        HASH_TABLE,
        STD_VECTOR,
        STD_UNORDERED_MAP
    };
    virtual void add(const std::string&value) = 0;
    virtual bool check(const std::string&value)const = 0;
    virtual Type get_type()const = 0;
    virtual std::string get_name()const = 0;
    //virtual ~Checker() = 0;
};
//Checker::~Checker() {}
#endif //SPELLER_CHECKER_H
