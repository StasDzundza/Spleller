//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_VECTORFACADE_H
#define SPELLER_VECTORFACADE_H

#include "checker.h"
#include <vector>
class VectorFacade : public Checker{
public:
    void add(const std::string&value)override;
    bool check(const std::string&value)const override;
    Type get_type()const override;
    std::string get_name()const override;
private:
    std::vector<std::string>words;
};


#endif //SPELLER_VECTORFACADE_H
