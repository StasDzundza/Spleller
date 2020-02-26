//
// Created by STAS on 24.02.2020.
//

#ifndef HASHTABLE_CHAINHASHTABLE_H
#define HASHTABLE_CHAINHASHTABLE_H

#include "checker.h"
#include <vector>

class ChainHashTable : public Checker{
public:
    void add(const std::string&value)override;
    bool check(const std::string&value)const override;
    int get_max_collisions()const;
private:
    int get_hash(const std::string&value)const;
    static const int SIZE = 1000;
    std::vector<std::string> hash_table[SIZE];
    Type get_type()const override;
};


#endif //HASHTABLE_CHAINHASHTABLE_H
