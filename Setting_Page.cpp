//
// Created by alessio on 19/03/19.
//

#include "Setting_Page.h"
#include "Menu_Game.h"
#include "Load_Exception.h"

Setting_Page::Setting_Page(RenderWindow &window, Error &error) {

    setWindow(error, window);

}

Setting_Page::~Setting_Page() = default;

void Setting_Page::draw(RenderWindow &window) {

    for (const auto &i : S_setting)
        window.draw(i);

}

int Setting_Page::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;

                case Keyboard::BackSpace:                         //con il tasto Return torniamo al manu principale
                    pageIndex = 0;
                    pageChanged=true;
                    break;
                default:
                    break;
            }
            break;

        case Event::MouseButtonReleased:

            if (Mouse::getPosition(window).x > 25 && Mouse::getPosition(window).x < 125 &&
                Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 115) {
                pageIndex = 0;
                pageChanged=true;
            }
            break;
        default:
            break;
    }

    return 0;

}

void Setting_Page::setWindow(Error &error, RenderWindow &window) {

    try {
        if (!T_setting[0].loadFromFile("Setting/impo.jpg")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_setting[0].setTexture(T_setting[0]);

        if (!T_setting[1].loadFromFile("Setting/indietro.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_setting[1].setTexture(T_setting[1]);
        S_setting[1].setPosition(sf::Vector2f(25, 25));

        if (!T_setting[2].loadFromFile("Setting/impostazioni.png")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_setting[2].setTexture(T_setting[2]);
        S_setting[2].setPosition(sf::Vector2f(220, 25));

        if (!T_setting[3].loadFromFile("Setting/istruzioni.png")) {       //pulsante2
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_setting[3].setTexture(T_setting[3]);
        S_setting[3].setPosition(sf::Vector2f(25, 470));

        if (!T_setting[4].loadFromFile("Setting/record.png")) {       //pulsante3
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_setting[4].setTexture(T_setting[4]);
        S_setting[4].setPosition(sf::Vector2f(350, 470));

        if (!T_setting[5].loadFromFile("Setting/riconoscimenti.png")) {       //pulsante4
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_setting[5].setTexture(T_setting[5]);
        S_setting[5].setPosition(sf::Vector2f(675, 470));
    }
    catch(Load_exception e){
        error.Check_Image(window);
    }

}

Menu_State *Setting_Page::getNewPage(RenderWindow &window, Error &error) {

    switch(pageIndex){
        case 0:
            return new Menu_Game(window, error);
        default:break;
    }
}
