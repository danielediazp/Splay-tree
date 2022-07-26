#include "Splay.h"

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
    const float zoom = 1.02f;
    sf::View view(sf::Vector2f(window_x/2,window_y/2), sf::Vector2f(window_x, window_y));


    std::srand(std::time(nullptr));
    std::vector<positionalNode> positional_nodes;
    sf::Text value;
    float startSpot = (800 + (4 * scale))/2;
    ////TODO: Size universally
    int size = 30;
    value.setCharacterSize(30);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Green);
    while (this->window->isOpen()) {

        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                std::cout << "//----------------------------//" << '\n';
                std::cout << "Application closed via input" << '\n';
                this->window->close();
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {

                    std::cout << "Enter a number to search for: " << "\n";
                    float temp;
                    std::cin >> temp;
                    window->clear();
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    this->tree->search(tree->root_, temp, this->window_x/2, 50, positional_nodes, window, scale/2, 'm', 0, splayed_tree, window_x/2);
                    window->display();
                    window->clear();

                    this->tree->splay_tree(temp);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();

                }
                if (event.key.code == sf::Keyboard::I) {
                    window->clear();
//                    std::cout << "Insert plz: " << "\n";
//                    float temp;
//                    std::cin >> temp;
//                    std::cout << "Enter Node to be Inserted: " << "\n";
//                    std::cin >> temp;
                    int temp = 1 + (rand() % 200);
                    next_node(temp, window, false);
//                    window->display();

                    this->tree->insert(temp , splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    std::cout << positional_nodes[0].coordinates.first << "\n";
                    window->display();
                } else if (event.key.code == sf::Keyboard::N){

                    view.zoom(.99f);
                    window->clear();
                    next_node(tree->root_->get_value(), window, false);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();
                    window->setView(view);

//                    view1.setSize(this->window_x, this->window_y);
//                    view1.setViewport(sf::FloatRect (0.25, 0.25, 0.5, 0.5));
////                    this->scale *= 0.5;
//                    window->setView(view1);
                }else if (event.key.code == sf::Keyboard::M){

                    view.zoom(1.01f);
                    window->clear();
                    next_node(tree->root_->get_value(), window, false);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();
                    window->setView(view);

//                    view1.setSize(this->window_x * 0.5 * scale, this->window_y * 0.5 * scale);
//                    view1.setViewport(sf::FloatRect (1.25, 1.25, 1.5, 1.5));
////                    this->scale *= 1.5;
                } else if (event.key.code == sf::Keyboard::Down){

                    view.move(0.f, 30.f);
                    window->clear();
                    next_node(tree->root_->get_value(), window, false);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();
                    window->setView(view);

//                    view1.setSize(this->window_x * 0.5 * scale, this->window_y * 0.5 * scale);
//                    view1.setViewport(sf::FloatRect (1.25, 1.25, 1.5, 1.5));
////                    this->scale *= 1.5;

                } else if (event.key.code == sf::Keyboard::Up){

                    view.move(0.f, -30.f);
                    window->clear();
                    next_node(tree->root_->get_value(), window, false);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();
                    window->setView(view);

//                    view1.setSize(this->window_x * 0.5 * scale, this->window_y * 0.5 * scale);
//                    view1.setViewport(sf::FloatRect (1.25, 1.25, 1.5, 1.5));
////                    this->scale *= 1.5;

                }else if (event.key.code == sf::Keyboard::Left){

                    view.move(-30.f, 0.f);
                    window->clear();
                    next_node(tree->root_->get_value(), window, false);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();
                    window->setView(view);

//                    view1.setSize(this->window_x * 0.5 * scale, this->window_y * 0.5 * scale);
//                    view1.setViewport(sf::FloatRect (1.25, 1.25, 1.5, 1.5));
////                    this->scale *= 1.5;

                } else if (event.key.code == sf::Keyboard::Right) {

                    view.move(30.f, 0.f);
                    window->clear();
                    next_node(tree->root_->get_value(), window, false);
                    this->tree->pre_order_vector(splayed_tree, window, scale, positional_nodes, this->window_x/2);
                    window->display();
                    window->setView(view);

//                    view1.setSize(this->window_x * 0.5 * scale, this->window_y * 0.5 * scale);
//                    view1.setViewport(sf::FloatRect (1.25, 1.25, 1.5, 1.5));
////                    this->scale *= 1.5;

                }  else if (event.key.code == sf::Keyboard::J && !this->deleteMode) {
                    splayed_tree.clear();
                    this->window->clear();
                    tree->pre_order_vector(splayed_tree, this->window, this->scale, positional_nodes, this->window_x/2);
                    this->window->display();
                    deleteMode = true;
                    std::cout << "Delete Mode Activated" << "\n";

                }
            }
//            std::cout << sf::Mouse::getPosition().x << "\n";
            if (event.mouseButton.button == sf::Mouse::Left && deleteMode == true) {
                std::cout << "CLICKED! ";
                for (int i = 0; i < positional_nodes.size(); ++i) {
                    std::cout << positional_nodes[i].coordinates.first << "\n";
                    std::cout << positional_nodes[i].coordinates.second << '\n';
                }
                std::pair<int, int> coord = std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                for (int i = 0; i < positional_nodes.size(); ++i) {
                    if (coord.first > positional_nodes[i].coordinates.first + 30 &&
                        coord.first < positional_nodes[i].coordinates.first + 82) {
                        if (coord.second > positional_nodes[i].coordinates.second + 1860 &&
                            coord.second < positional_nodes[i].coordinates.second + 1910) {
                            if (positional_nodes[i].value_ != nullptr) {
                                tree->delete_node(positional_nodes[i].value_->get_value());
                                std::cout << "Delete Mode Toggled: OFF - Node has been removed" << "\n";
                                positional_nodes.clear();
                                window->clear();
                                next_node(positional_nodes[i].value_->get_value(), window, true);
                                tree->pre_order_vector(splayed_tree, this->window, scale, positional_nodes, this->window_x/2);
                                window->display();
                                deleteMode = false;
                                break;
                            }
                        }
                    }
                }
                deleteMode = false;
            }
        }
    }
}

void Splay::next_node(int val, sf::RenderWindow * window, bool type) {
    int size = 30;
    sf::CircleShape node;
    node.setRadius(size);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    node.setOutlineThickness(5);
    node.setOutlineColor(sf::Color::Green);
    sf::Text value;
    value.setCharacterSize(size);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Green);

    std::string string_value = ("Inserting Node:  ");
    if (type) {
        string_value = ("Deleting Node");
    }
    value.setString(string_value);
    value.setPosition(50, 50);

    node.setPosition(300, 45);
    if (!type) {
        window->draw(node);

    }
    window->draw(value);

    string_value = std::to_string(val);
    value.setString(string_value);
    value.setPosition(310, 55);
    if (!type) {
        window->draw(value);
    }

//    window->display();
}
