#include "Splay.h"


/*
TODO: Render nodes correctly in terms of ancestry and position (i.e., right children should be to the right of a node, etc.) (HARD)
TODO: Write code to create new nodes using the SplayTree methods on user input (MEDIUM)
TODO: Write function to delete nodes by clicking on them (bounds checking/input handling) (VERY HARD)
TODO: Write function to insert nodes in valid empty spaces (bounds checking/input handling) (VERY HARD)
     4a, 5a. Create a key-press toggle for insert and delete modes (EASY)
TODO: Come up with some form of animation for deleting and inserting nodes (via built-in SFML functions) (EXTREMELY HARD)
 */

Splay::Splay() {
    this->scale = 500;
    this->window = new sf::RenderWindow(sf::VideoMode(800 + (4 * scale), 800 + (2 * scale)), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->tree = new SplayTree();
    this->deleteMode = false;
    this->global_font.loadFromFile("../Butler_Regular.otf");
}

void Splay::run(std::vector<Node*> splayed_tree) {
    std::vector <positionalNode> positional_nodes;
    sf::Text value;

    ////TODO: Size universally
    int size = 30;
    value.setCharacterSize(30);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Red);
    this->tree->insert(40);
    this->tree->insert(50);
    this->tree->insert(43);
    this->tree->insert(45);
    this->tree->insert(44);
    this->tree->insert(47);
    this->tree->insert(46);
    this->tree->insert(30);
    this->tree->insert(35);
    this->tree->insert(41);
    this->tree->insert(39);
    this->tree->insert(41);
    this->tree->insert(51);
    this->tree->insert(20);
    this->tree->insert(45);
    this->tree->insert(25);
    this->tree->insert(47);
    this->tree->insert(46);
    this->tree->insert(30);
    this->tree->insert(35);
    this->tree->insert(41);
    this->tree->insert(39);
    tree->pre_order_vector(splayed_tree, this->window, this->scale, positional_nodes);
    std::cout << positional_nodes[0].value_ << "\n";
//    for (int i = 0; i < splayed_tree.size(); ++i) {
//        if (splayed_tree[i] == nullptr) {
//            continue;
//        }
//        std::cout << splayed_tree[i]->get_value() << "\n";
//    }

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
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::pair<int, int> coord = std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                std::cout << coord.first << ", " << coord.second << "\n";
                std::cout << positional_nodes[0].coordinates.first << ", " << positional_nodes[0].coordinates.second
                          << "\n";
                for (int i = 0; i < positional_nodes.size(); ++i) {
                    if (coord.first > positional_nodes[i].coordinates.first + 30 &&
                        coord.first < positional_nodes[i].coordinates.first + 82) {
                        if (coord.second > positional_nodes[i].coordinates.second + 1860 &&
                            coord.second < positional_nodes[i].coordinates.second + 1910) {
                            std::cout << "yo" << '\n';
                            if (positional_nodes[i].value_ != nullptr) {
                                tree->delete_node(positional_nodes[i].value_->get_value());
                                window->clear();
                                tree->pre_order_vector(splayed_tree, this->window, this->scale, positional_nodes);
                                window->display();
                            }
                        }
                    }
                }
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
                        tree->pre_order_vector(splayed_tree, this->window, this->scale, positional_nodes);


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
