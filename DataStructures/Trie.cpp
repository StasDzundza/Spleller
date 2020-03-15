//
// Created by stas on 15.03.2020.
//

#include "Trie.h"

namespace {
    const int a_ASCII_CODE = 97;
    const int NUMBER_OF_LETTERS = 26;
}

void Trie::add(const std::string &word) {
    if (root == nullptr) {
        root = std::make_unique<Node>(Node());
    }

    Node *current_node = root.get();
    int current_letter;

    for (int i = 0; i < word.length(); i++) {
        current_letter = word.at(i) - a_ASCII_CODE;
        if (current_letter < 0) {
            current_letter = NUMBER_OF_LETTERS;
        }
        if (current_node->nodes[current_letter] == nullptr) {
            current_node->nodes[current_letter] = std::make_unique<Node>(Node());;
        }
        current_node = current_node->nodes[current_letter].get();
    }

    current_node->isWord = true;
}

bool Trie::check(const std::string &word) const {
    Node *current_node = root.get();
    if (!current_node) {
        return false;
    }

    int current_letter;

    for (int i = 0; i < word.length(); i++) {
        current_letter = word.at(i) - a_ASCII_CODE;
        if (current_letter < 0) {
            current_letter = NUMBER_OF_LETTERS;
        }
        if (current_node->nodes[current_letter] == nullptr) {
            return false;
        }
        current_node = current_node->nodes[current_letter].get();
    }

    if (current_node and current_node->isWord) {
        return true;
    } else {
        return false;
    }
}

Checker::Type Trie::get_type() const {
    return Checker::Type::TRIE;
}

std::string Trie::get_name() const {
    return "trie";
}



