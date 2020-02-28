//
// Created by STAS on 26.02.2020.
//
#include "BinaryTree.h"

BinaryTree::BinaryTree():head(nullptr) {
}

BinaryTree::BinaryTree(node*head):head(head){
}

void BinaryTree::add(const std::string& value) {
    if(!head)
        head = _add(value);
    else{
        _add(value);
    }
}

typename BinaryTree::node* BinaryTree::_add(const std::string &value) {
    node* newnode = new node;
    newnode->value = value;
    newnode->left = newnode->right = nullptr;

    node* x = head;
    node* y = nullptr;

    while (x != nullptr) {
        y = x;
        if (value < x->value)
            x = x->left;
        else
            x = x->right;
    }
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == nullptr)
        y = newnode;
    else if (value < y->value)
        y->left = newnode;
    else
        y->right = newnode;
    // Returns the pointer where the
    // new node is inserted
    return y;
}

bool BinaryTree::check(const std::string& value)const {
    node* x = head;

    while (x != NULL) {
        if (value < x->value)
            x = x->left;
        else if(value > x->value)
            x = x->right;
        else
            return true;
    }
    return false;
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
    return false;
}

Checker::Type BinaryTree::get_type() const {
    return Type::BIN_TREE;
}

std::string BinaryTree::get_name() const {
    return "binary_tree";
}

void BinaryTree::clear(node**current) {
    if (*current != nullptr){
        clear(&(*current)->left);
        clear(&(*current)->right);
        delete *current;
        *current = nullptr;
    }
}

BinaryTree::~BinaryTree() {
    clear(&head);
}




