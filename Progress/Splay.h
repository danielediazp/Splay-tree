#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <Event.hpp>
#include "SplayTree.h"
#include "Node.h"


#ifndef SPLAY_H
#define SPLAY_H

class Splay {
private:
    sf::RenderWindow *window;
    SplayTree *tree;
    bool deleteMode;
    sf::Font global_font;
    float scale;
    unsigned int window_x = 800 + (4 * scale);
    unsigned int window_y = 800 + (2 * scale);

public:
    Splay();
    void run(std::vector<Node *> splayed_tree);
    void next_node(int val, sf::RenderWindow *window, bool type);

    friend class SplayTree;
};

#endif
