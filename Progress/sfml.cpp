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

Game::Game() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
    this->tree = new SplayTree();
    this->deleteMode = false;
}

void Game::run(){
    while (this->window->isOpen()){
        sf::Event event;
        sf::Vector2i localPos = sf::Mouse::getPosition(*this->window);
        // std::cout << "X: " << localPos.x << " Y: " << localPos.y << "\n";
        while (this->window->pollEvent(event)){
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
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
    this->update();
    this->render();
    }
}

void Game::update(){
    sf::CircleShape circle = createNode();
    this->window->draw(circle);
}

void Game::render(){
    this->window->clear();
    this->update();
    this->window->display();
}

sf::CircleShape Game::createNode(){
    sf::CircleShape node;
    // BELOW IS AN ATTEMPT AT ANIMATING NODES FOR NO REASON
    // This code is super buggy and very laggy
    sf::Clock clock1;
    while (clock1.getElapsedTime() < sf::seconds(5)){
        node.setRadius(clock1.getElapsedTime().asSeconds() * 2);
    }
    std::cout << clock1.getElapsedTime().asSeconds() << '\n';
    clock1.restart();
    node.setFillColor(sf::Color::White);
    node.setPosition(400, 50);
    // if (root == nullptr){
       
    // } else if (root->value_ < root->left_->value_){
        
    // }
    return node;
}
//https://en.sfml-dev.org/forums/index.php?topic=26818.0
//take a look at this, it might help