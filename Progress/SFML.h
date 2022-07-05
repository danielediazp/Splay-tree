#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <mutex>
#include "SplayTree.h"

class Game {
private:
    sf::RenderWindow *window;
    static sf::CircleShape createNode();
    SplayTree *tree;
    bool deleteMode;
public:
    Game();
    void run();
    void update();
    void render();

};