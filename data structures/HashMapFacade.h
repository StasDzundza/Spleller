//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_HASHMAPFACADE_H
#define SPELLER_HASHMAPFACADE_H

#include "checker.h"
#include <unordered_map>

class HashMapFacade : public Checker{
public:
    void add(const std::string& value)override;
    bool check(const std::string& value)const override;
private:
    std::unordered_map<std::string,std::string> words;
};


#endif //SPELLER_HASHMAPFACADE_H
