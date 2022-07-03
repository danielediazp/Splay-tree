// #include "SplayTree.h"
#include "SFML.h"
#include <GLUT/glut.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Splay Tree");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}