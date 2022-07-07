#include "Splay.h"

struct positionalNode{
    Node *value_ = nullptr;
    std::pair<int, int> coordinates = std::make_pair(385, 50);
};

/*
TODO: Render nodes correctly in terms of ancestry and position (i.e., right children should be to the right of a node, etc.) (HARD)
TODO: Write code to create new nodes using the SplayTree methods on user input (MEDIUM)
TODO: Write function to delete nodes by clicking on them (bounds checking/input handling) (VERY HARD)
TODO: Write function to insert nodes in valid empty spaces (bounds checking/input handling) (VERY HARD)
     4a, 5a. Create a key-press toggle for insert and delete modes (EASY)
TODO: Come up with some form of animation for deleting and inserting nodes (via built-in SFML functions) (EXTREMELY HARD)
 */

Splay::Splay() {
    this->scale = 2;
    this->window = new sf::RenderWindow(sf::VideoMode(800 * scale, 800 * scale), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->tree = new SplayTree();
    this->deleteMode = false;
    this->global_font.loadFromFile("../Butler_Regular.otf");
}

void Splay::run(std::vector<Node*> splayed_tree) {
    std::vector <positionalNode> positional_nodes;
    sf::Text value;
    value.setCharacterSize(30);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Red);
    this->tree->insert(60);
    this->tree->insert(40);
    this->tree->insert(70);
    this->tree->insert(45);
    this->tree->insert(57);
//    this->tree->insert(42);
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
                    this->counter = 0;
                    this->level = 1;
                    tree->BFS(splayed_tree);
                    for (int i = 0; i < splayed_tree.size(); i ++) {
                        positionalNode temp;
                        temp.value_ = splayed_tree[i];
                        positional_nodes.push_back(temp);
                    }
                    PrintTree(splayed_tree);
                    sf::CircleShape node;
                    sf::CircleShape papa;
                    std::string string_value;
                    for (int i = 0; i < splayed_tree.size(); i++) {
                        if (this->counter == this->level) {
                            this->level *= 2;
                            this->counter = 0;
                        }
                        if (i == 0) {
                            string_value = std::to_string(splayed_tree[i]->get_value());
                            papa = create_node(385, 50, splayed_tree, 't');
                            positional_nodes[i].coordinates = std::make_pair(385 * scale, 50 * scale);
                            value.setString(string_value);
                            value.setPosition(positional_nodes[i].coordinates.first, positional_nodes[i].coordinates.second);
                            this->window->draw(value);
                            std::cout << "Drew node: " << splayed_tree[i]->get_value() << " My coordinates are -> " << papa.getPosition().x << " " << papa.getPosition().y << '\n';
                        } else {
                            papa.setPosition(positional_nodes[i].coordinates.first, positional_nodes[i].coordinates.second);
                        }
                        if (is_left_child(i, splayed_tree)) {
                            if (splayed_tree[i * 2 + 1] == nullptr){
                                continue;
                            }
//                            std::cout << node.getPosition().x << " " << node.getPosition().y << '\n';
                            node = create_node(papa.getPosition().x, papa.getPosition().y, splayed_tree, 'l');
                            positional_nodes[i * 2 + 1].coordinates = std::make_pair(node.getPosition().x * scale, node.getPosition().y * scale);
                            string_value = std::to_string(splayed_tree[i]->get_value());
                            value.setString(string_value);
                            value.setPosition(positional_nodes[i * 2 + 1].coordinates.first, positional_nodes[i * 2 + 1].coordinates.second);
                            this->window->draw(value);
                            std::cout << "Drew node: " << splayed_tree[i * 2 + 1]->get_value() << " I am a left child of " << splayed_tree[i]->get_value() << " coordinates -> " << papa.getPosition().x << " " << papa.getPosition().y << '\n';
                        }
                        if (is_right_child(i, splayed_tree)) {
                            if (splayed_tree[i * 2 + 2] == nullptr){
                                continue;
                            }
//                            std::cout << node.getPosition().x << " " << node.getPosition().y << '\n';
                            node = create_node(papa.getPosition().x, papa.getPosition().y, splayed_tree, 'r');
                            positional_nodes[i * 2 + 2].coordinates = std::make_pair(node.getPosition().x * scale, node.getPosition().y * scale);
                            string_value = std::to_string(splayed_tree[i *2 + 2]->get_value());
                            value.setString(string_value);
                            value.setPosition(positional_nodes[i * 2 + 2].coordinates.first, positional_nodes[i * 2 + 2].coordinates.second);
                            this->window->draw(value);

                            std::cout << "Drew node: " << splayed_tree[i*2 + 2]->get_value() << " I am a right child of " << splayed_tree[i]->get_value() << "  coordinates -> " << papa.getPosition().x << " " << papa.getPosition().y << '\n';
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

bool Splay::is_left_child(int i, std::vector<Node*> &target_tree){
    if (target_tree[(i*2) + 1] != nullptr){
        if ((i * 2) + 1 < target_tree.size()){
            return true;
        }
    }
    return false;
}

bool Splay::is_right_child(int i, std::vector<Node*> &target_tree){
    if (target_tree[(i*2) + 2] != nullptr){
        if ((i * 2) + 2 < target_tree.size()){
            return true;
        }
    }
    return false;
}

bool Splay::is_parent(int i, std::vector<Node*> &target_tree){
    if (target_tree[floor(i/2)] != nullptr){
        return true;
    }
    return false;
}

sf::CircleShape Splay::create_node(int prior_node_x, int prior_node_y, std::vector<Node*> &target_tree, const char type){
    sf::CircleShape node;
    node.setRadius(20.f * scale);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    switch(type){
        case 'l':
            // Left child node
            node.setPosition(prior_node_x - 50, prior_node_y + 50);
            break;
        case 'r':
            // Right child node
            node.setPosition(prior_node_x + 50, prior_node_y + 50);
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
