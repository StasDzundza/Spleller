//
// Created by STAS on 24.02.2020.
//

#include "ChainHashTable.h"
#include <algorithm>

void ChainHashTable::add(const std::string &value) {
    int hash = get_hash(value);
    hash_table[hash].push_back(value);
}

bool ChainHashTable::check(const std::string &value)const {
    int hash = get_hash(value);
    bool found = false;
    auto it = std::find(hash_table[hash].begin(), hash_table[hash].end(), value);
    if(it!=hash_table[hash].end())
        found = true;
    return found;
}

int ChainHashTable::get_max_collisions()const {
    int max_collisions = 0;
    for(int i = 0; i < SIZE; i++){
        if(hash_table[i].size() > max_collisions){
            max_collisions = hash_table[i].size();
        }
    }
    return max_collisions;
}

int ChainHashTable::get_hash(const std::string &key)const {
    int hash = 0;
    for(int i = 0; i < key.size(); i++){
        hash+=key[i];
    }
    hash = hash%SIZE;
    return hash;
}

Checker::Type ChainHashTable::get_type() const {
    return Type ::HASH_TABLE;
}

std::string ChainHashTable::get_name() const {
    return "hash_table";
}

ChainHashTable::~ChainHashTable() {}


