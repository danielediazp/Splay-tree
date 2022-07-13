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

void Menu::run(sf::RenderWindow &window){

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
                    sf::RenderWindow Play(sf::VideoMode(960, 720), "Splay-Tree");
                    sf::RenderWindow OPTIONS(sf::VideoMode(960, 720), "HOW TO USE");
                    sf::RenderWindow ABOUT(sf::VideoMode(960, 720), "ABOUT");

                    int x = menu_pressed();
                    if (x == 0) {
                        Splay splay;
                        std::vector<Node *> splay_tree;
                        splay.run(splay_tree);

                        OPTIONS.close();
                        ABOUT.close();
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
                            Play.close();
                            OPTIONS.clear();
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
                            Play.close();
                            OPTIONS.close();
                            ABOUT.clear();
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
        draw(window);
        window.display();
    }
}