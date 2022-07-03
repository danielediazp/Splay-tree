#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Game {
private:
    sf::RenderWindow window;
public:
    Game();
    void initWindow();
    void gameLoop();
};