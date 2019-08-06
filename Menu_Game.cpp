//
// Created by alessio on 13/03/19.
//

#include "Menu_Game.h"
#include "Championship_Page.h"
#include "SingleRace_Page.h"
#include "TimeTrial_Page.h"
#include "Setting_Page.h"
#include "Load_Exception.h"

Menu_Game::Menu_Game(RenderWindow &window, Error &error) {

    setWindow(error, window);

}

Menu_Game::~Menu_Game() = default;

void Menu_Game::draw(RenderWindow &window) {

            for (const auto &i : S_menu)
                window.draw(i);

}

int Menu_Game::getActivities(Event event, RenderWindow &window) {

    switch(event.type){

        case Event::KeyReleased:

            switch(event.key.code){

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;
                default:break;
            }
            break;
        case Event::MouseButtonReleased:

            if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 970 &&
                Mouse::getPosition(window).y > 170 && Mouse::getPosition(window).y < 240) {
                pageIndex = 1;
                pageChanged=true;
            }

            if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 970 &&
                Mouse::getPosition(window).y > 270 && Mouse::getPosition(window).y < 340) {
                pageIndex = 2;
                pageChanged=true;

            }

            if (Mouse::getPosition(window).x > 625 && Mouse::getPosition(window).x < 970 &&
                Mouse::getPosition(window).y > 370 && Mouse::getPosition(window).y < 440) {
                pageIndex = 4;
                pageChanged=true;
            }

            if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 970 &&
                Mouse::getPosition(window).y > 470 && Mouse::getPosition(window).y < 540) {
                pageIndex = 5;
                pageChanged=true;
            }
            break;
        default:break;
    }

    return 0;
}

Menu_State *Menu_Game::getNewPage(RenderWindow &window, Error &error) {

    switch (pageIndex){
        case 1:
            return new Championship_Page(window, error);

        case 2:
            return new SingleRace_Page(window, error);

        case 4:
            return new TimeTrial_Page(window, error);

        case 5:
            return new Setting_Page(window, error);

        default: break;
    }
}

void Menu_Game::setWindow(Error &error, RenderWindow &window) {

    try {

        if (!T_menu[0].loadFromFile("Menu/2307.jpg"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_menu[0].setTexture(T_menu[0]);

        if (!T_menu[1].loadFromFile("Menu/titolo.png"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_menu[1].setTexture(T_menu[1]);
        S_menu[1].setPosition(sf::Vector2f(220, 25));

        if (!T_menu[2].loadFromFile("Menu/carriera.png"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_menu[2].setTexture(T_menu[2]);
        S_menu[2].setPosition(sf::Vector2f(650, 170));

        if (!T_menu[3].loadFromFile("Menu/gara singola.png"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_menu[3].setTexture(T_menu[3]);
        S_menu[3].setPosition(sf::Vector2f(650, 270));

        if (!T_menu[4].loadFromFile("Menu/prova a tempo.png"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_menu[4].setTexture(T_menu[4]);
        S_menu[4].setPosition(sf::Vector2f(650, 370));

        if (!T_menu[5].loadFromFile("Menu/impostazioni.png"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_menu[5].setTexture(T_menu[5]);
        S_menu[5].setPosition(sf::Vector2f(650, 470));
    }
    catch(Load_exception e){
        error.Check_Image(window);
    }
}

