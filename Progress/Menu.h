#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef FINAL_212_MENU_H
#define FINAL_212_MENU_H

#define Max_main_menu 4

class Menu {

private:
    int menu_selected;
    sf::Font font;
    sf::Text main_menu[Max_main_menu];

public:
    Menu (float width, float height);
    void draw(sf::RenderWindow &window);
    void move_up();
    void move_down();

    int menu_pressed(){
        return this->menu_selected;
    }

    ~Menu();

};


#endif //FINAL_212_MENU_H