#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include "SplayTree.h"
#include "Node.h"


#ifndef SPLAY_H
#define SPLAY_H

class Splay {
private:
    sf::RenderWindow *window;
    SplayTree *tree;
    bool deleteMode;
    int level = 1;
    int counter = 0;
    sf::Font global_font;
    float scale;

public:
    Splay();
    void run(std::vector<Node *> splayed_tree);
    void update();
    void render();

    friend class SplayTree;
};

#endif
