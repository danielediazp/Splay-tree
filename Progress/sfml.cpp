#include "SFML.h"
/*
TODO: Accept user input in the form of a text file (EASY)
TODO: Render nodes correctly in terms of ancestry and position (i.e., right children should be to the right of a node, etc.) (HARD)
TODO: Write code to create new nodes using the SplayTree methods on user input (MEDIUM)
TODO: Write function to delete nodes by clicking on them (bounds checking/input handling) (VERY HARD)
TODO: Write function to insert nodes in valid empty spaces (bounds checking/input handling) (VERY HARD)
     4a, 5a. Create a key-press toggle for insert and delete modes (EASY)
TODO: Come up with some form of animation for deleting and inserting nodes (via built-in SFML functions) (EXTREMELY HARD)
TODO: Write created tree to a DOT file (MEDIUM)
 */

Splay::Splay() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->tree = new SplayTree();
    this->deleteMode = false;
}

void Splay::run(){
    sf::Font font;
    font.loadFromFile("Vogue.ttf");
    sf::String Text;

    while (this->window->isOpen()){
        sf::Event event;
        sf::Vector2i localPos = sf::Mouse::getPosition(*this->window);
        // std::cout << "X: " << localPos.x << " Y: " << localPos.y << "\n";
        while (this->window->pollEvent(event)){
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
                std::cout << "----------------------------" << '\n';
                std::cout << "Application closed via input" << '\n';
                this->window->close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::T){
                    if (!this->deleteMode) {
                        this->deleteMode = true;
                        // TODO: DRAW THE FACT THAT DELETE MODE IS ON NEXT TO THE CURSOR
                        // CHANGE LOGIC SO THAT ONLY DELETION IS ALLOWED
                        std::cout << "Delete Mode Toggled: ON" << '\n';
                    } else {
                        this->deleteMode = false;
                        // TODO: DRAW THE FACT THAT INSERT MODE IS ON NEXT TO THE CURSOR
                        // CHANGE LOGIC SO THAT ONLY INSERTION IS ALLOWED
                        std::cout << "Delete Mode Toggled: OFF" << '\n';
                    }
                }
            }
        }
    this->render();
    }
}

void Splay::update(){
    sf::CircleShape circle = createNode();
    this->window->draw(circle);
}

void Splay::render(){
    this->window->clear();
    this->update();
    this->window->display();
}

sf::CircleShape Splay::createNode(){
    sf::CircleShape node;
    node.setRadius(20.f);
    node.setFillColor(sf::Color::White);
    node.setPosition(400, 50);
    return node;
}
//https://en.sfml-dev.org/forums/index.php?topic=26818.0