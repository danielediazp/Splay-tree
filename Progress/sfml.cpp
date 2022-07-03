#include "SFML.h"

// TODO:
// 1. Accept user input in the form of a text file (EASY)
// 2. Render nodes correctly in terms of ancestry and position (i.e., right children should be to the right of a node, etc.) (HARD)
// 3. Write code to create new nodes using the SplayTree methods on user input (MEDIUM)
// 4. Write function to delete nodes by clicking on them (bounds checking/input handling) (VERY HARD)
// 5. Write function to insert nodes in valid empty spaces (bounds checking/input handling) (VERY HARD)
//      4a, 5a. Create a key-press toggle for insert and delete modes (EASY)
// 6. Come up with some form of animation for deleting and inserting nodes (via built-in SFML functions) (EXTREMELY HARD)
// 7. Write created tree to a DOT file

Game::Game() {
    this->initWindow();
    this->tree = new SplayTree();
    this->deleteMode = false;
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
}

void Game::run(){
    while (this->window->isOpen()){
        sf::Event event;
        sf::Vector2i localPos = sf::Mouse::getPosition(*this->window);
        // std::cout << "X: " << localPos.x << " Y: " << localPos.y << "\n";
        while (this->window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                this->window->close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::T){
                    if (!this->deleteMode) {
                        this->deleteMode = true;
                        // DRAW THE FACT THAT DELETE MODE IS ON NEXT TO THE CURSOR
                        // CHANGE LOGIC SO THAT ONLY DELETION IS ALLOWED
                        std::cout << "Delete Mode Toggled: ON" << '\n';
                    } else {
                        this->deleteMode = false;
                        // DRAW THE FACT THAT INSERT MODE IS ON NEXT TO THE CURSOR
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
    sf::CircleShape circle = createNode(this->tree->root_);
    this->window->draw(circle);
}

void Game::render(){
    this->window->clear();
    this->update();
    this->window->display();
}

sf::CircleShape Game::createNode(Node *root){
    sf::CircleShape node;
    node.setRadius(20);
    node.setFillColor(sf::Color::White);
    node.setPosition(400, 50);
    // if (root == nullptr){
       
    // } else if (root->value_ < root->left_->value_){
        
    // }
    return node;
}
//https://en.sfml-dev.org/forums/index.php?topic=26818.0
//take a look at this, it might help