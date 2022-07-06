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
}

void Splay::run(std::vector<Node *> splayed_tree) {
    this->tree->insert(60);
    this->tree->insert(40);
    this->tree->insert(50);
    this->tree->insert(47);
    this->tree->insert(55);
    this->tree->insert(45);
//    tree->pre_order();
//    std::cout << std::endl;
    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                std::cout << "//----------------------------//" << '\n';
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
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::J && !this->deleteMode) {
                    splayed_tree.clear();
                    this->window->clear();
                    tree->BFS(splayed_tree);
                    for (int i = 0; i < splayed_tree.size(); i ++){
                        if (splayed_tree[i] == nullptr){
                            std::cout << "null" << " ";
                            continue;
                        }
                        std::cout << splayed_tree[i]->get_value() << " ";
                    }
                    std::cout << std::endl;
                    sf::CircleShape node;
                    sf::CircleShape papa;
                    for (int i = 0; i < splayed_tree.size(); i++) {
                        if (this->counter == this->level) {
                            this->level *= 2;
                            this->counter = 0;
                        }

                        if (i == 0) {
                            papa = create_node(385, 50, splayed_tree, 't');
                            std::cout << "Drew node: " << splayed_tree[i]->get_value() << " My coordinates are -> " << node.getPosition().x << " " << node.getPosition().y << '\n';
                        } 
                        if (is_left_child(i, splayed_tree)) {
                            if (splayed_tree[i * 2 + 1] == nullptr){
                                continue;
                            }
//                            std::cout << node.getPosition().x << " " << node.getPosition().y << '\n';
                            node = create_node(papa.getPosition().x, papa.getPosition().y, splayed_tree, 'l');
                            std::cout << "Drew node: " << splayed_tree[i*2 + 1]->get_value() << " I am a left child of coordinates -> " << node.getPosition().x << " " << node.getPosition().y << '\n';
                        }
                        if (is_right_child(i, splayed_tree)) {
                            if (splayed_tree[i * 2 + 2] == nullptr){
                                continue;
                            }
//                            std::cout << node.getPosition().x << " " << node.getPosition().y << '\n';
                            node = create_node(papa.getPosition().x, papa.getPosition().y, splayed_tree, 'r');
                            std::cout << "Drew node: " << splayed_tree[i*2 + 2]->get_value() << " I am a right child of coordinates -> " << node.getPosition().x << " " << node.getPosition().y << '\n';
                        }
                        counter++;
                    }
                    this->window->display();
                }
            }
        }
    }
}

void Splay::update(){
}

void Splay::render(){
//    this->window->clear(sf::Color::Black);
    this->update();
    this->window->display();
}

bool Splay::is_left_child(int i, std::vector<Node *> &target_tree){
    if (target_tree[(i*2) + 1] != nullptr){
        if ((i * 2) + 1 < target_tree.size()){
            return true;
        }
    }
    return false;
}

bool Splay::is_right_child(int i, std::vector<Node *> &target_tree){
    if (target_tree[(i*2) + 2] != nullptr){
        if ((i * 2) + 2 < target_tree.size()){
            return true;
        }
    }
    return false;
}

bool Splay::is_parent(int i, std::vector<Node *> &target_tree){
    if (target_tree[floor(i/2)] != nullptr){
        return true;
    }
    return false;
}

sf::CircleShape Splay::create_node(int prior_node_x, int prior_node_y, std::vector<Node *> &target_tree, const char type){
    sf::CircleShape node;
    node.setRadius(20.f);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    std::pair<int, int> temp_offset;
    switch(type){
        case 'l':
            // Left child node
            temp_offset = std::make_pair(-50 * this->level, 50 * this->level);
            node.setPosition(prior_node_x + temp_offset.first, prior_node_y + temp_offset.second);
            std::cout << "I am at coordinates: " << prior_node_x + temp_offset.first << ", " << prior_node_y + temp_offset.second << "\n";
            break;
        case 'r':
            // Right child node
            temp_offset = std::make_pair(50 * this->level, 50 * this->level);
            node.setPosition(prior_node_x + temp_offset.first, prior_node_y + temp_offset.second);
            std::cout << "I am at coordinates: " << prior_node_x + temp_offset.first << ", " << prior_node_y + temp_offset.second << "\n";
            break;
        case 't':
            // Root node
            node.setPosition(prior_node_x, prior_node_y);
            break;
        default:
            break;
    }
    this->window->draw(node);
    return node;
}

void Splay::PrintTree(std::vector<Node *> target_vector){
    for (int i = 0; i < target_vector.size(); i ++){
        if (target_vector[i] == nullptr){
            std::cout << "null" << " ";
            continue;
        }
        std::cout << target_vector[i]->get_value() << " ";
    }
    std::cout << std::endl;
}