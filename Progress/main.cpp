#include "Splay.h"
#include "Menu.h"

int main() {

//
//    Splay splay;
//    std::vector<Node*> splay_tree;
//    splay.run(splay_tree);

    sf::RenderWindow MENU(sf::VideoMode(960, 720), "Main Menu", sf::Style::Default);
    Menu main_menu  (MENU.getSize().x, MENU.getSize().y);
    main_menu.run(MENU);
    return 0;
}