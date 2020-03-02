//
// Created by STAS on 26.02.2020.
//
#include "BinaryTree.h"
#include <queue>

BinaryTree::BinaryTree() : mHead(nullptr) {
}

BinaryTree::BinaryTree(Node *head) : mHead(head) {
}

void BinaryTree::add(const std::string &value) {
    // start with mHead node
    Node *curr = mHead;
    // pointer to store parent node of current node
    Node *parent = nullptr;

    // if tree is empty, create a new node and set root
    if (mHead == nullptr) {
        mHead = new Node(value);
        return;
    }
    // traverse the tree and find parent node of key
    while (curr != nullptr) {
        // update parent node as current node
        parent = curr;
        if (value < curr->value) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    // construct a new node and assign to appropriate parent pointer
    if (value < parent->value) {
        parent->left = new Node(value);
    } else {
        parent->right = new Node(value);
    }
}

bool BinaryTree::check(const std::string &value) const {
    Node *current_node = mHead;

    while (current_node != nullptr) {
        if (value < current_node->value)
            current_node = current_node->left;
        else if (value > current_node->value)
            current_node = current_node->right;
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

BinaryTree::~BinaryTree() {
    // not empty tree
    if (mHead != nullptr) {
        // create an empty queue and enqueue root node
        std::queue<Node *> queue;
        queue.push(mHead);
        Node *front = nullptr;
        // run till queue is not empty
        while (!queue.empty()) {
            // delete each node in the queue one by one after pushing their
            // non-empty left and right child to the queue
            front = queue.front();
            queue.pop();
            if (front->left) {
                queue.push(front->left);
            }
            if (front->right) {
                queue.push(front->right);
            }
            // Important - delete front node ONLY after enqueuing its children
            delete front;
        }
    }
}




