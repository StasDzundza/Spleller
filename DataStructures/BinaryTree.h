//
// Created by STAS on 17.02.2020.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "checker.h"

class BinaryTree : public Checker{
public:
    struct Node{
        Node():left(nullptr),right(nullptr){}
        Node(const std::string& value):Node(){
            this->value = value;
        }
        Node*left;
        Node*right;
        std::string value;
    };

    BinaryTree();
    BinaryTree(Node*head);
    void add(const std::string& value)override;
    bool check(const std::string& value)const override;
    Type get_type()const override;
    std::string get_name()const override;
    ~BinaryTree()override;
private:
    Node*mHead;
    Node* _add(const std::string& value);
    void clear(Node**current);
};

#endif //BINARYTREE_TREE_H
