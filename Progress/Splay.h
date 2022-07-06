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
    static sf::CircleShape createNode();
    SplayTree *tree;
    bool deleteMode;

public:
    Splay();

    void run(std::vector<int> splayed_tree);
    void update();
    void render();
};

#endif