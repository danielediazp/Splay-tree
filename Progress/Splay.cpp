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
    this->tree->insert(52);
    this->tree->insert(43);
    tree->pre_order();
    std::cout << std::endl;
    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event)) {
            splayed_tree.clear();
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
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::J && !this->deleteMode) {
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
                    for (int i = 0; i < splayed_tree.size(); i++) {
                        if (i == 0) {
                            node = create_node(385, 50, splayed_tree, 't');
                            std::cout << "Drew node: " << splayed_tree[i]->get_value() << '\n';
                            continue;
                        }
                        if (is_left_child(i, splayed_tree)) {
                            node = create_node(node.getPosition().x, node.getPosition().y, splayed_tree, 'l');
                            if (splayed_tree[i] == nullptr){
                                continue;
                            }
                            std::cout << "Drew node: " << splayed_tree[i]->get_value() << '\n';
                        }
                        if (is_right_child(i, splayed_tree)) {
                            node = create_node(node.getPosition().x, node.getPosition().y, splayed_tree, 'r');
                            if (splayed_tree[i] == nullptr){
                                continue;
                            }
                            std::cout << "Drew node: " << splayed_tree[i]->get_value() << '\n';
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

sf::CircleShape Splay::create_node(int prior_node_x, int prior_node_y, std::vector<Node *> &target_tree, const char type){
    sf::CircleShape node;
    node.setRadius(20.f);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    std::pair<int, int> temp_offset;
    switch(type){
        case 'l':
            temp_offset = std::make_pair(-10 * this->counter, 10 * this->counter);
            node.setPosition(prior_node_x + temp_offset.first, prior_node_y + temp_offset.second);
            break;
        case 'r':
            temp_offset = std::make_pair(10 * this->counter, 10 * this->counter);
            node.setPosition(prior_node_x + temp_offset.first, prior_node_y + temp_offset.second);
            break;
        case 't':
            node.setPosition(prior_node_x, prior_node_y);
            break;
        default:
            break;
    }
    this->window->draw(node);
    return node;
}