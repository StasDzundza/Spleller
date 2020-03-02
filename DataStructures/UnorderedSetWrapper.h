//
// Created by STAS on 26.02.2020.
//

#ifndef SPELLER_UNORDEREDSETWRAPPER_H
#define SPELLER_UNORDEREDSETWRAPPER_H

#include "checker.h"
#include <unordered_set>

class UnorderedSetWrapper : public Checker {
public:
    void add(const std::string &value) override;

    bool check(const std::string &value) const override;

    Type get_type() const override;

    std::string get_name() const override;

    ~UnorderedSetWrapper() override;

private:
    std::unordered_set<std::string> words;
};


#endif //SPELLER_UNORDEREDSETWRAPPER_H
