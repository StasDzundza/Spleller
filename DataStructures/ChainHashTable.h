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
    Type get_type()const override;
    std::string get_name()const override;
    ~ChainHashTable()override ;
private:
    int get_hash(const std::string&value)const;
    static const int SIZE = 2000;
    std::vector<std::string> hash_table[SIZE];
};


#endif //HASHTABLE_CHAINHASHTABLE_H
