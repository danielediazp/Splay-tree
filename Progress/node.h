#ifndef SPLAY_TREE_NODE_H
#define SPLAY_TREE_NODE_H

class Node{
private:
    int value_;
    Node *left_, *right_;
    int counter_;

public:
    Node(int data): value_(data), left_(nullptr), right_(nullptr){}
    int get_value(){
        return this->value_;
    };
    ~Node(){}

    friend class SplayTree;
    friend class Game;
};

#endif //SPLAY_TREE_NODE_H
