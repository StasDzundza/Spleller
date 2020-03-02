//
// Created by STAS on 26.02.2020.
//

#include "VectorWrapper.h"
#include <algorithm>

void VectorWrapper::add(const std::string &value) {
    words.emplace_back(value);
}

bool VectorWrapper::check(const std::string &value) const {
    return (std::binary_search(words.begin(), words.end(), value));
}

Checker::Type VectorWrapper::get_type() const {
    return Type::STD_VECTOR;
}

std::string VectorWrapper::get_name() const {
    return "std_vector";
}

VectorWrapper::~VectorWrapper() {}

