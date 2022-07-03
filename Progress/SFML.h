#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "SplayTree.h"

class Game {
private:
    sf::RenderWindow *window;
    sf::CircleShape createNode(Node *root);
    SplayTree *tree;
    bool deleteMode;
public:
    Game();
    void initWindow();
    void run();
    void update();
    void render();

};