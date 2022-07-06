#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "SplayTree.h"

#ifndef SPLAY_H
#define SPLAY_H

class Splay {
private:
    sf::RenderWindow *window;
    SplayTree *tree;
    bool deleteMode;
    int level = 1;
    int counter = 0;


public:
    Splay();

    void PrintTree(std::vector<Node *> target_vector);
    bool is_right_child(int i, std::vector<Node *> &tree);
    bool is_left_child(int i, std::vector<Node *> &tree);
    sf::CircleShape create_node(int prior_node_x, int prior_node_y, std::vector<Node *> &target_tree, char type);
    bool is_parent(int i, std::vector<Node *> &target_tree);
    void run(std::vector<Node *> splayed_tree);
    void update();
    void render();

    friend class SplayTree;
};

#endif