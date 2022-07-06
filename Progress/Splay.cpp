#include "Splay.h"

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
    this->counter = 1;
}

void Splay::run(std::vector<int> splayed_tree) {
    this->tree->insert(60);
    this->tree->insert(40);
    this->tree->insert(50);
    this->tree->insert(55);
//    this->tree->insert(52);
    while (this->window->isOpen()) {
        sf::Event event;
        sf::Vector2i localPos = sf::Mouse::getPosition(*this->window);
//        std::cout << "X: " << localPos.x << " Y: " << localPos.y << "\n";
        while (this->window->pollEvent(event)) {
            splayed_tree.clear();
            this->counter = 1;
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                std::cout << "----------------------------" << '\n';
                std::cout << "Application closed via input" << '\n';
                this->window->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::T) {
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
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::J && !this->deleteMode) {
                    this->window->clear(sf::Color::Black);
                    tree->BFS(splayed_tree);
                    for (std::vector<int>::const_iterator i = splayed_tree.begin(); i != splayed_tree.end(); i ++){
                        std::cout << *i << " ";
                    }
                    std::cout << std::endl;
                    for (int i = 0; i < splayed_tree.size(); i++) {
                        if (i == 0) {
                            std::pair<int, int> root(0, 0);
                            sf::CircleShape newNode = this->createNode(root);
                            this->window->draw(newNode);

                        }
                        std::cout << "Drawing root:" << splayed_tree[i] << '\n';
                        if (is_left_child(i, splayed_tree)) {
                            std::cout << "Drawing left child: " <<  i << '\n';
                            std::cout << "Drawing value: " << splayed_tree[(i * 2) + 1] << '\n';
                            std::pair<int, int> temp_offset(-50 * this->counter, 50 * this->counter);
                            sf::CircleShape newNode = this->createNode(temp_offset);
                            this->window->draw(newNode);
                        } if (is_right_child(i, splayed_tree)) {
                            std::cout << "Drawing right child: " << i << '\n';
                            std::cout << "Drawing value: " << splayed_tree[(i * 2) + 2] << '\n';
                            std::cout << "------------------" << '\n';
                            std::pair<int, int> temp_offset(50 * this->counter, 50 * this->counter);
                            sf::CircleShape newNode = this->createNode(temp_offset);
                            this->window->draw(newNode);
                        }
                        std::cout << "LOOP DONE" << '\n';
                        counter++;
                    }

                }
            }

            this->window->display();
        }
    }
}

void Splay::update(){
}

void Splay::render(){
    this->window->clear();
    this->update();
    this->window->display();
}

sf::CircleShape Splay::createNode(std::pair<int, int> offset){
    sf::CircleShape node;
    node.setRadius(20.f);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    if (offset.first < 0){
        node.setPosition(385 + offset.first, 50 + offset.second);
    } else if (offset.first > 0) {
        node.setPosition(385 + offset.first, 50 + offset.second);
    } else {
        node.setPosition(385, 50);
    }
    return node;
}

bool Splay::is_left_child(int i, std::vector<int> &target_tree){
    if (i * 2 + 1 < target_tree.size() && target_tree[(i * 2) + 1] != 0){
        return true;
    }
    return false;
}

bool Splay::is_right_child(int i, std::vector<int> &target_tree){
    if (i * 2 + 2 < target_tree.size() && target_tree[(i * 2) + 2] != 0){
        return true;
    }
    return false;
}

bool Splay::is_parent(int i, std::vector<int> &target_tree){
    if (target_tree[floor((i)/2)] != 0){
        return true;
    }
    return false;
}
