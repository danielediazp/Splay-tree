#include "Splay.h"
#include "Menu.h"

int main() {

    sf::RenderWindow MENU(sf::VideoMode(1650, 1050), "Main Menu", sf::Style::Default);
    Menu main_menu  (MENU.getSize().x, MENU.getSize().y);
    main_menu.run(MENU);
    return 0;
}