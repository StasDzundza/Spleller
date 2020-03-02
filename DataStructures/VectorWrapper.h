//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_VECTORWRAPPER_H
#define SPELLER_VECTORWRAPPER_H

#include "checker.h"
#include <vector>
class VectorWrapper : public Checker{
public:
    void add(const std::string&value)override;
    bool check(const std::string&value)const override;
    Type get_type()const override;
    std::string get_name()const override;
    ~VectorWrapper()override;
private:
    std::vector<std::string>words;
};


#endif //SPELLER_VECTORWRAPPER_H
