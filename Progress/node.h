#ifndef SPLAY_TREE_NODE_H
#define SPLAY_TREE_NODE_H

class Node{

private:
    int value_;
    Node *left_, *right_;

public:
    Node(int data): value_(data), left_(nullptr), right_(nullptr){}
    ~Node(){

    }

    friend class SplayTree;
};

#endif //SPLAY_TREE_NODE_H
