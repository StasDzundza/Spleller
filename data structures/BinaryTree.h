//
// Created by STAS on 17.02.2020.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "checker.h"

class BinaryTree : public Checker{
public:
    struct node{
        node*left;
        node*right;
        std::string value;
    };

    BinaryTree();
    BinaryTree(node*head);
    void add(const std::string& value)override;
    bool check(const std::string& value)const override;
    Type get_type()const override;

private:
    node*head;

    void _add(node**current,const std::string& value);
    bool _check(node*current,const std::string& value)const;
};

#endif //BINARYTREE_TREE_H
