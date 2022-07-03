#include "SFML.h"
#include "SplayTree.h"

Game::Game() {
    this->initWindow();
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
}

void Game::run(){
    SplayTree tree(5);
    while (this->window->isOpen()){
        sf::Event event;
        sf::Vector2i localPos = sf::Mouse::getPosition(*this->window);
        // std::cout << "X: " << localPos.x << " Y: " << localPos.y << "\n";
        while (this->window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                this->window->close();
            }

            this->update();
            this->window->clear();
            sf::CircleShape newNode = createNode(tree.root_);
            this->window->draw(newNode);
            this->window->display();
        }
    }
    this->render();
}

void Game::update(){
}

void Game::render(){

    this->window->display();
}

sf::CircleShape Game::createNode(Node *root){
    sf::CircleShape node;
    node.setRadius(20);
    node.setFillColor(sf::Color::White);
    if (root == nullptr){
        node.setPosition(400, 50);
    } else if (root->value_ < root->left_->value_){
        
    }
    

    return node;
}
// humor me for a second
//https://en.sfml-dev.org/forums/index.php?topic=26818.0
//take a look at this, it might help