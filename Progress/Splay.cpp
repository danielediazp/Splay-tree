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
    this->window->setFramerateLimit(144);
    this->tree = new SplayTree();
    this->deleteMode = false;
    this->counter = 1;
}

void Splay::run(std::vector<Node *> splayed_tree) {
    this->tree->insert(60);
    this->tree->insert(40);
    this->tree->insert(50);
    this->tree->insert(55);
    this->tree->insert(45);
    this->tree->pre_order();
    while (this->window->isOpen()) {
        sf::Event event;
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
                    for (int i = 0; i < splayed_tree.size(); i++) {
                        if (i == 0) {
                            create_node(splayed_tree, 't');
                        }
                        if (is_left_child(i, splayed_tree)) {
                            create_node(splayed_tree, 'l');
                        }
                        if (is_right_child(i, splayed_tree)) {
                            create_node(splayed_tree, 'r');
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

bool Splay::is_left_child(int i, std::vector<Node *> &target_tree){
    if (target_tree[(i*2) + 1] != nullptr){
        if (i * 2 + 1 < target_tree.size()){
            return true;
        }
    }
    return false;
}

bool Splay::is_right_child(int i, std::vector<Node *> &target_tree){
    if (target_tree[(i*2) + 2] != nullptr){
        if (i * 2 + 2 < target_tree.size()){
            return true;
        }
    }
    return false;
}

bool Splay::is_parent(int i, std::vector<int> &target_tree){
    if (target_tree[floor((i)/2)] != 0){
        return true;
    }
    return false;
}

void Splay::create_node(std::vector<Node *> &target_tree, const char type){
    sf::CircleShape node;
    node.setRadius(20.f);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    std::pair<int, int> temp_offset;
    if (type == 'l'){
        // Left child node
        temp_offset = std::make_pair(-50 * this->counter, 50 * this->counter);
        node.setPosition(385 + temp_offset.first, 50 + temp_offset.second);
    } else if (type == 'r'){
        // Right child node
        temp_offset = std::make_pair(50 * this->counter, 50 * this->counter);
        node.setPosition(385 + temp_offset.first, 50 + temp_offset.second);
    } else if (type == 't'){
        // Root node
        node.setPosition(385, 50);
    }
    this->window->draw(node);
}
