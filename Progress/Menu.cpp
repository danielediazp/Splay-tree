#include "Menu.h"

Menu::Menu(float width, float height) {
    font.loadFromFile("../coolvetica.otf");

    this->window_height_ = height;
    this->window_width_ = width;

    //Play
    main_menu[0].setFont(font);
    main_menu[0].setFillColor(sf::Color::Green);
    main_menu[0].setString("Play");
    main_menu[0].setCharacterSize(90);
    main_menu[0].setPosition(this->window_width_/2,250);

    //How to use
    main_menu[1].setFont(font);
    main_menu[1].setFillColor(sf::Color::White);
    main_menu[1].setString("How to use?");
    main_menu[1].setCharacterSize(90);
    main_menu[1].setPosition(this->window_width_/2,350);

    //About
    main_menu[2].setFont(font);
    main_menu[2].setFillColor(sf::Color::White);
    main_menu[2].setString("About");
    main_menu[2].setCharacterSize(90);
    main_menu[2].setPosition(this->window_width_/2,450);

    //Exit
    main_menu[3].setFont(font);
    main_menu[3].setFillColor(sf::Color::White);
    main_menu[3].setString("Exit");
    main_menu[3].setCharacterSize(90);
    main_menu[3].setPosition(this->window_width_/2,550);

    menu_selected = 0;
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
        main_menu[menu_selected].setFillColor(sf::Color::Green);
    }
}

void Menu::move_down() {
    if (menu_selected + 1 <= Max_main_menu){
        main_menu[menu_selected].setFillColor(sf::Color::White);
        menu_selected++;
        if (menu_selected == 4){
            menu_selected = 0;
        }
        main_menu[menu_selected].setFillColor(sf::Color::Green);
    }
}

void Menu::run(sf::RenderWindow &window){

    //set About background
    sf::RectangleShape about_background;
    about_background.setSize(sf::Vector2f(this->window_width_,this->window_height_));
    sf::Texture about_window_texture;
    about_window_texture.loadFromFile("../Splay-tree/Progress/backgrounds/aboutbg.jpg");
    about_background.setTexture(&about_window_texture);

    //set How to background
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(this->window_width_,this->window_height_));
    sf::Texture back_texture;
    back_texture.loadFromFile("../Splay-tree/Progress/backgrounds/howtobg.jpg");
    background.setTexture(&back_texture);

    //set main menu background
    sf::RectangleShape main_background;
    main_background.setSize(sf::Vector2f(this->window_width_,this->window_height_));
    sf::Texture main_texture;
    main_texture.loadFromFile("../Splay-tree/Progress/backgrounds/main_menu.jpg");
    main_background.setTexture(&main_texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    move_up();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    move_down();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return) {
                    sf::RenderWindow OPTIONS(sf::VideoMode(this->window_width_, this->window_height_), "HOW TO USE");
                    sf::RenderWindow ABOUT(sf::VideoMode(this->window_width_, this->window_height_), "ABOUT");

                    int x = menu_pressed();
                    if (x == 0) {
                        OPTIONS.close();
                        ABOUT.close();
                        Splay splay;
                        std::vector<Node *> splay_tree;
                        splay.run(splay_tree);
                    }

                    if (x == 1) {
                        while (OPTIONS.isOpen()) {
                            sf::Event event1;
                            while (OPTIONS.pollEvent(event1)) {
                                if (event1.type == sf::Event::Closed) {
                                    OPTIONS.close();
                                }
                                if (event1.type == sf::Event::KeyPressed) {
                                    if (event1.key.code == sf::Keyboard::Escape) {
                                        OPTIONS.close();
                                    }
                                }
                            }
                            OPTIONS.clear();
                            OPTIONS.draw(background);
                            ABOUT.close();
                            OPTIONS.display();
                        }
                    }
                    if (x == 2) {
                        while (ABOUT.isOpen()) {
                            sf::Event event1;
                            while (ABOUT.pollEvent(event1)) {
                                if (event1.type == sf::Event::Closed) {
                                    ABOUT.close();
                                }
                                if (event1.type == sf::Event::KeyPressed) {
                                    if (event1.key.code == sf::Keyboard::Escape) {
                                        ABOUT.close();
                                    }
                                }
                            }
                            OPTIONS.close();
                            ABOUT.clear();
                            ABOUT.draw(about_background);
                            ABOUT.display();
                        }
                    }
                    if (x == 3)
                        window.close();
                    break;

                }
            }
        }
        window.clear();
        window.draw(main_background);
        draw(window);
        window.display();
    }
}
