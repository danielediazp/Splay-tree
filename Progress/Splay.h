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
    sf::CircleShape createNode(std::pair<int, int> offset);
    SplayTree *tree;
    bool deleteMode;
    int counter;

public:
    Splay();

    bool is_right_child(int i, std::vector<Node *> &tree);
    bool is_left_child(int i, std::vector<Node *> &tree);
    void create_node(std::vector<Node *> &target_tree, const char type);
    bool is_parent(int i, std::vector<Node *> &target_tree);
    void run(std::vector<Node *> splayed_tree);
    void update();
    void render();
};

#endif