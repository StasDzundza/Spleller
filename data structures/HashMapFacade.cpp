//
// Created by STAS on 26.02.2020.
//

#include "HashMapFacade.h"
#include <algorithm>

void HashMapFacade::add(const std::string &value) {
    words.insert(std::make_pair(value,value));
}

bool HashMapFacade::check(const std::string &value) const {
    if(words.find(value) != words.end())
        return true;
    else
        return false;
}

Checker::Type HashMapFacade::get_type() const {
    return Type::STD_UNORDERED_MAP;
}

std::string HashMapFacade::get_name() const {
    return "std_unordered_map";
}

HashMapFacade::~HashMapFacade() {}
