#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "SplayTree.h"

class Game {
private:
    sf::RenderWindow *window;
    sf::CircleShape createNode();
    SplayTree *tree;
    bool deleteMode;
public:
    Game();
    void run();
    void update();
    void render();

};