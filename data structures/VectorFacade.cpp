//
// Created by STAS on 26.02.2020.
//

#include "VectorFacade.h"
#include <utility>
#include <algorithm>
void VectorFacade::add(const std::string &value) {
    words.push_back(value);
}

bool VectorFacade::check(const std::string &value) const {
    if(std::find(words.begin(),words.end(),value) != words.end())
        return true;
    else
        return false;
}

