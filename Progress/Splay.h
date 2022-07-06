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

    bool is_right_child(int i, std::vector<int> &tree);
    bool is_left_child(int i, std::vector<int> &tree);
    bool is_parent(int i, std::vector<int> &target_tree);
    void run(std::vector<int> splayed_tree);
    void update();
    void render();
};

#endif