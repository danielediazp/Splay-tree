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
    this->window_x = 800 + (4 * scale);
    this->window_y = 800 + (2 * scale);
    this->window = new sf::RenderWindow(sf::VideoMode(window_x, window_y), "Splay Tree", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->tree = new SplayTree();
    this->deleteMode = false;
    this->global_font.loadFromFile("../coolvetica.otf");
}

void Splay::run(std::vector<Node*> splayed_tree) {
    std::srand(std::time(nullptr));
    std::vector<positionalNode> positional_nodes;
    sf::Text value;
    float startSpot = (800 + (4 * scale))/2;
    ////TODO: Size universally
    int size = 30;
    value.setCharacterSize(30);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Red);
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
                if (event.key.code == sf::Keyboard::I) {
                    std::cout << "Insert plz: " << "\n";
                    float temp;
                    std::cin >> temp;
                    next_node(temp, window);
                    window->display();
                    this->tree->insert(temp, splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();

                }
            }

            if (event.mouseButton.button == sf::Mouse::Left && deleteMode == true) {
                std::pair<int, int> coord = std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                for (int i = 0; i < positional_nodes.size(); ++i) {
                    if (coord.first > positional_nodes[i].coordinates.first + 30 &&
                        coord.first < positional_nodes[i].coordinates.first + 82) {
                        if (coord.second > positional_nodes[i].coordinates.second + 1860 &&
                            coord.second < positional_nodes[i].coordinates.second + 1910) {
                            int size = 30;
                            sf::CircleShape node;
                            node.setRadius(size);
                            node.setFillColor(sf::Color::Yellow);
                            node.setOrigin(0.0f, 0.0f);
                            sf::Text value;
                            value.setCharacterSize(size);
                            value.setFont(this->global_font);
                            value.setFillColor(sf::Color::Red);
                            node.setPosition(positional_nodes[i].coordinates.first,
                                             positional_nodes[i].coordinates.second);
                            std::string string_value = std::to_string(positional_nodes[i].value_->get_value());
                            value.setString(string_value);
                            value.setPosition(positional_nodes[i].coordinates.first,
                                              positional_nodes[i].coordinates.second);
                            window->draw(node);
                            window->draw(value);
                            window->display();
                            if (positional_nodes[i].value_ != nullptr) {
                                tree->delete_node(positional_nodes[i].value_->get_value());
                                std::cout << "Delete Mode Toggled: OFF - Node has been removed" << "\n";
                                positional_nodes.clear();
                                window->clear();
                                tree->pre_order_vector(splayed_tree, this->window, scale, positional_nodes, this->window_x/2);
                                window->display();
                                deleteMode = false;
                                break;

                            }
                        }
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::J && !this->deleteMode) {
                    splayed_tree.clear();
                    this->window->clear();
                    tree->pre_order_vector(splayed_tree, this->window, this->scale, positional_nodes, this->window_x/2);


                    this->window->display();
                }
            }
        }
    }
}

void Splay::next_node(int val, sf::RenderWindow * window) {
    int size = 30;
    sf::CircleShape node;
    node.setRadius(size);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    node.setOutlineThickness(5);
    node.setOutlineColor(sf::Color::Red);
    sf::Text value;
    value.setCharacterSize(size);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Black);

    std::string string_value = ("Inserting Node:  ");
    value.setString(string_value);
    value.setPosition(50, 50);

    node.setPosition(300, 45);

    window->draw(node);
    window->draw(value);

    string_value = std::to_string(val);
    value.setString(string_value);
    value.setPosition(310, 55);

    window->draw(value);

}
