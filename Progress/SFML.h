#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "SplayTree.h"
#include "Node.h"

class Game {
private:
    sf::RenderWindow *window;
    sf::CircleShape createNode(Node * root);
public:
    Game();
    void initWindow();
    void run();
    void update();
    void render();

};