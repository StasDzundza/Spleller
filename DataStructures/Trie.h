//
// Created by stas on 15.03.2020.
//

#ifndef SPELLER_TRIE_H
#define SPELLER_TRIE_H

#include "checker.h"
#include <memory>
#include <unordered_map>

struct Node{
    Node() : isWord(false) {}

    std::unique_ptr<Node>nodes[27];
    bool isWord;
};

class Trie : public Checker{
public:

    void add(const std::string &word) override ;

    bool check(const std::string &word)const override ;

    Type get_type() const override;

    std::string get_name() const override;

private:
    std::unique_ptr<Node> root;
};


#endif //SPELLER_TRIE_H
