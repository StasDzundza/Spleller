//
// Created by STAS on 26.02.2020.
//
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    head = nullptr;
}

BinaryTree::BinaryTree(node*head) {
    this->head = head;
}

void BinaryTree::add(const std::string& value) {
    _add(&head,value);
}

void BinaryTree::_add(node **current, const std::string& value) {
    if (!*current) {
        *current = new node;
        (*current)->value = value;
        (*current)->left = nullptr;
        (*current)->right = nullptr;
        return;
    }
    if (value < (*current)->value)
        _add(&(*current)->left, value);
    else if(value > (*current)->value)
        _add(&(*current)->right, value);
    else
        return;
}

bool BinaryTree::check(const std::string& value)const {
    node*current = head;
    return _check(current,value);
}

bool BinaryTree::_check(node *current, const std::string& value)const {
    if(!current){
        return false;
    } else if (current->value == value){
        return true;
    }else{
        if(value<current->value){
            _check(current->left,value);
        }else{
            _check(current->right,value);
        }
    }
}

Checker::Type BinaryTree::get_type() const {
    return Type::BIN_TREE;
}

std::string BinaryTree::get_name() const {
    return "binary_tree";
}
