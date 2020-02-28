//
// Created by STAS on 26.02.2020.
//

#include "VectorFacade.h"
#include <algorithm>

void VectorFacade::add(const std::string &value) {
    words.emplace_back(value);
}

bool VectorFacade::check(const std::string &value) const {
    if(std::binary_search(words.begin(), words.end(), value))
        return true;
    else
        return false;
}

Checker::Type VectorFacade::get_type() const {
    return Type::STD_VECTOR;
}

std::string VectorFacade::get_name() const {
    return "std_vector";
}

VectorFacade::~VectorFacade() {}

