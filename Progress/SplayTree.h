#include "node.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

#ifndef SPLAY_TREE_SPLAYTREE_H
#define SPLAY_TREE_SPLAYTREE_H


class SplayTree {

private:
    Node* root_;

    Node* insert(int data, Node* root);
    Node* splay_tree(int data, Node* root);
    Node* delete_node(int data, Node *root);
    Node* left_rotate(Node* root);
    Node* right_rotate(Node* root);
    void level_order(Node *root, int l, std::vector<int> &target_vector);
    void destroy(Node* root);

    void inorder(Node* root);
    void pre_order(Node* root);
    void post_order(Node* root);
    int height(Node* root);
    void BFS(Node *root, std::vector<int> &target_vector);


public:
    SplayTree();
    SplayTree(int root);
    SplayTree(std::string file_name);
    ~SplayTree();

    void insert(int key);
    void splay_tree(int key);
    void delete_node(int key);

    int height();
    int get_root();

    void pre_order();
    void post_order();
    void inorder();
    void BFS(std::vector<int> &target_vector);


    friend class Game;
};


#endif //SPLAY_TREE_SPLAYTREE_H
