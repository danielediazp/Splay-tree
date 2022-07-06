#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <mutex>
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
    void run();
    void update();
    void render();

};

#endif