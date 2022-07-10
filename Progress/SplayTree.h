#include "Node.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef SPLAY_TREE_SPLAYTREE_H
#define SPLAY_TREE_SPLAYTREE_H

struct positionalNode{
    Node *value_ = nullptr;
    std::pair<int, int> coordinates = std::make_pair(385, 50);
    positionalNode(Node *value_, float x, float y) {
        this->value_ = value_;
        coordinates = std::make_pair(x, y);
    }

};

class SplayTree {

private:
    Node* root_;

    Node* insert(int data, Node* root);
    Node* splay_tree(int data, Node* root);
    Node* delete_node(int data, Node *root);
    Node* left_rotate(Node* root);
    Node* right_rotate(Node* root);
    void level_order(Node *root, int l, std::vector<Node *> &target_vector);
    void pre_order_vector(Node* root, std::vector<Node*> &target_vector, int x, int y, sf::RenderWindow *window, char type, float scale, std::vector<positionalNode> &positional_nodes);
    void destroy(Node* root);

    void inorder(Node* root);
    void pre_order(Node* root);
    void post_order(Node* root);
    int height(Node* root);
    void BFS(Node *root, std::vector<Node *> &target_vector);


public:
    SplayTree();
    SplayTree(int root);
    SplayTree(std::string file_name);
    ~SplayTree();

    void insert(int key, std::vector<Node *> &target_vector, sf::RenderWindow *window, float scale, std::vector<positionalNode> &positional_nodes);
    void splay_tree(int key);
    void delete_node(int key);

    int height();
    int get_root();
    void force_delay();
    void pre_order();
    void post_order();
    void inorder();
    void BFS(std::vector<Node *> &target_vector);
    void pre_order_vector(std::vector<Node *> &target_vector, sf::RenderWindow *window, float scale, std::vector<positionalNode> &positional_nodes);


    friend class Splay;
};


#endif //SPLAY_TREE_SPLAYTREE_H
