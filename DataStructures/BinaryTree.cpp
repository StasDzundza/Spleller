//
// Created by STAS on 26.02.2020.
//
#include "BinaryTree.h"

BinaryTree::BinaryTree():mHead(nullptr) {
}

BinaryTree::BinaryTree(Node*head): mHead(head){
}

void BinaryTree::add(const std::string& value) {
    if(!mHead)
        mHead = _add(value);
    else{
        _add(value);
    }
}

typename BinaryTree::Node* BinaryTree::_add(const std::string &value) {
    Node* newnode = new Node(value);
    Node* current_node = mHead;
    Node* auxiliary_node = nullptr;

    while (current_node != nullptr) {
        auxiliary_node = current_node;
        if (value < current_node->value)
            current_node = current_node->left;
        else
            current_node = current_node->right;
    }
    // If the root is NULL i.e the tree is empty
    // The new Node is the root Node
    if (auxiliary_node == nullptr)
        auxiliary_node = newnode;
    else if (value < auxiliary_node->value)
        auxiliary_node->left = newnode;
    else
        auxiliary_node->right = newnode;
    // Returns the pointer where the
    // new Node is inserted
    return auxiliary_node;
}

bool BinaryTree::check(const std::string& value)const {
    Node* x = mHead;

    while (x != nullptr) {
        if (value < x->value)
            x = x->left;
        else if(value > x->value)
            x = x->right;
        else
            return true;
    }
    return false;
}

Checker::Type BinaryTree::get_type() const {
    return Type::BIN_TREE;
}

std::string BinaryTree::get_name() const {
    return "binary_tree";
}

void BinaryTree::clear(Node**current) {
    if (*current != nullptr){
        clear(&(*current)->left);
        clear(&(*current)->right);
        delete *current;
    }
}

BinaryTree::~BinaryTree() {
    clear(&mHead);
}




