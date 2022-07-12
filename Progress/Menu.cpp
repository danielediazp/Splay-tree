#include "Menu.h"

Menu::Menu(float width, float height) {
    font.loadFromFile("../coolvetica.otf");

    //Play
    main_menu[0].setFont(font);
    main_menu[0].setFillColor(sf::Color::White);
    main_menu[0].setString("Play");
    main_menu[0].setCharacterSize(70);
    main_menu[0].setPosition(400,200);

    //How to use
    main_menu[1].setFont(font);
    main_menu[1].setFillColor(sf::Color::White);
    main_menu[1].setString("How to use?");
    main_menu[1].setCharacterSize(70);
    main_menu[1].setPosition(400,300);

    //About
    main_menu[2].setFont(font);
    main_menu[2].setFillColor(sf::Color::White);
    main_menu[2].setString("About");
    main_menu[2].setCharacterSize(70);
    main_menu[2].setPosition(400,400);

    //Exit
    main_menu[3].setFont(font);
    main_menu[3].setFillColor(sf::Color::White);
    main_menu[3].setString("Exit");
    main_menu[3].setCharacterSize(70);
    main_menu[3].setPosition(400,500);

    menu_selected = -1;
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for (int buttons = 0; buttons < Max_main_menu; buttons++){
        window.draw(main_menu[buttons]);
    }
}

void Menu::move_up() {
    if (menu_selected - 1 >= 0){
        main_menu[menu_selected].setFillColor(sf::Color::White);
        menu_selected--;
        if (menu_selected == -1){
            menu_selected = 2;
        }
        main_menu[menu_selected].setFillColor(sf::Color::Blue);
    }
}

void Menu::move_down() {
    if (menu_selected + 1 <= Max_main_menu){
        main_menu[menu_selected].setFillColor(sf::Color::White);
        menu_selected++;
        if (menu_selected == 4){
            menu_selected = 0;
        }
        main_menu[menu_selected].setFillColor(sf::Color::Blue);
    }
}

void Menu::run() {

}