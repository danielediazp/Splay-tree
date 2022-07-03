#include "node.h"

#ifndef SPLAY_TREE_SPLAYTREE_H
#define SPLAY_TREE_SPLAYTREE_H


class SplayTree {

private:
    Node* root_;

    Node* insert(int data, Node* root);
    Node* splay_tree(int data, Node* root);
    bool search(int data, Node *root);
    Node* left_rotate(Node* root);
    Node* right_rotate(Node* root);
    void destroy(Node* root);

    void inorder(Node* root);
    void pre_order(Node* root);
    void post_order(Node* root);
    int height(Node* root);

public:
    SplayTree();
    SplayTree(int root);
    ~SplayTree();

    void insert(int key);
    void splay_tree(int key);
    bool search(int key);

    int height();
    int get_root();

    void pre_order();
    void post_order();
    void inorder();

};


#endif //SPLAY_TREE_SPLAYTREE_H
