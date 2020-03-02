//
// Created by STAS on 26.02.2020.
//

#include "UnorderedSetWrapper.h"
#include <algorithm>

void UnorderedSetWrapper::add(const std::string &value) {
    words.insert(value);
}

bool UnorderedSetWrapper::check(const std::string &value) const {
    return (words.find(value) != words.end());
}

Checker::Type UnorderedSetWrapper::get_type() const {
    return Type::STD_UNORDERED_SET;
}

std::string UnorderedSetWrapper::get_name() const {
    return "std_unordered_set";
}

UnorderedSetWrapper::~UnorderedSetWrapper() {}
