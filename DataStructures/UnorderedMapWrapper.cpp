//
// Created by STAS on 26.02.2020.
//

#include "UnorderedMapWrapper.h"
#include <algorithm>

void UnorderedMapWrapper::add(const std::string &value) {
    words.insert(std::make_pair(value,value));
}

bool UnorderedMapWrapper::check(const std::string &value) const {
    return (words.find(value) != words.end());
}

Checker::Type UnorderedMapWrapper::get_type() const {
    return Type::STD_UNORDERED_MAP;
}

std::string UnorderedMapWrapper::get_name() const {
    return "std_unordered_map";
}

UnorderedMapWrapper::~UnorderedMapWrapper() {}
