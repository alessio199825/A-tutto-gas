//
// Created by alessio on 19/03/19.
//

#include "TimeTrial_Page.h"
#include "Menu_Game.h"
#include "Load_Page.h"
#include "Load_Exception.h"

TimeTrial_Page::TimeTrial_Page(RenderWindow &window, Error &error) {

    setWindow(error, window);
    meteo=false;
    circuitrace=0;

}

TimeTrial_Page::~TimeTrial_Page() = default;

void TimeTrial_Page::draw(RenderWindow &window) {

    for (int i = 0; i < 7; i++) {
        window.draw(S_timetrial[i]);
    }

    switch (circuitrace) {
        case 1:
            window.draw(S_timetrial[7]);
            break;
        case 2:
            window.draw(S_timetrial[8]);
            break;
        case 3:
            window.draw(S_timetrial[9]);
            break;
        default:
            break;
    }

}

int TimeTrial_Page::getActivities(Event event, RenderWindow &window) {

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
                pageIndex=0;
                pageChanged=true;
            }

            if (Mouse::getPosition(window).x > 50 && Mouse::getPosition(window).x < 310 &&
                Mouse::getPosition(window).y > 390 && Mouse::getPosition(window).y < 585) { //tasto circuito 1
                circuitrace = 1;
            }

            if (Mouse::getPosition(window).x > 350 && Mouse::getPosition(window).x < 610 &&
                Mouse::getPosition(window).y > 390 && Mouse::getPosition(window).y < 585) {     //tasto circuito 2
                circuitrace = 2;
            }

            if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 910 &&
                Mouse::getPosition(window).y > 390 && Mouse::getPosition(window).y < 585) {     //tasto circuito 3
                circuitrace = 3;
            }

            if (Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 920 &&
                Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 115) {
                pageIndex = 9;
                pageChanged=true;
                Type_race=3;
            }
            break;
        default:
            break;
    }

    return 0;

}

void TimeTrial_Page::setWindow(Error &error, RenderWindow &window) {

    try {
        if (!T_timetrial[0].loadFromFile("Time_Trial/prova a tempo.jpg")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[0].setTexture(T_timetrial[0]);

        if (!T_timetrial[1].loadFromFile("Time_Trial/indietro.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[1].setTexture(T_timetrial[1]);
        S_timetrial[1].setPosition(sf::Vector2f(25, 25));

        if (!T_timetrial[2].loadFromFile("Time_Trial/seleziona circuito.png")) {       //seleziona circuito
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[2].setTexture(T_timetrial[2]);
        S_timetrial[2].setPosition(sf::Vector2f(50, 290));

        if (!T_timetrial[3].loadFromFile("Time_Trial/avanti1.png")) {       //scritta avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[3].setTexture(T_timetrial[3]);
        S_timetrial[3].setPosition(sf::Vector2f(600, 25));

        if (!T_timetrial[4].loadFromFile("Time_Trial/circuit2.jpg")) {       //circuito 1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[4].setTexture(T_timetrial[4]);
        S_timetrial[4].setPosition(sf::Vector2f(50, 390));

        if (!T_timetrial[5].loadFromFile("Time_Trial/circuit1-1.jpg")) {       //circuito 2
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[5].setTexture(T_timetrial[5]);
        S_timetrial[5].setPosition(sf::Vector2f(350, 390));

        if (!T_timetrial[6].loadFromFile("Time_Trial/circuit3-1.jpg")) {       //circuito 3
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[6].setTexture(T_timetrial[6]);
        S_timetrial[6].setPosition(sf::Vector2f(650, 390));

        if (!T_timetrial[7].loadFromFile("Time_Trial/circuit2on.jpg")) {       //circuito 1 modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[7].setTexture(T_timetrial[7]);
        S_timetrial[7].setPosition(sf::Vector2f(50, 390));

        if (!T_timetrial[8].loadFromFile("Time_Trial/circuit1on.jpg")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[8].setTexture(T_timetrial[8]);
        S_timetrial[8].setPosition(sf::Vector2f(350, 390));

        if (!T_timetrial[9].loadFromFile("Time_Trial/circuit3on.jpg")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_timetrial[9].setTexture(T_timetrial[9]);
        S_timetrial[9].setPosition(sf::Vector2f(650, 390));
    }
    catch(Load_exception e){
        error.Check_Image(window);
    }

}

Menu_State *TimeTrial_Page::getNewPage(RenderWindow &window, Error &error) {
    switch(pageIndex) {
        case 0:
            return new Menu_Game(window, error);
        case 9:
            return new Load_Page(window, error, circuitrace, Type_race, meteo, giri, chooseCar);
        default:break;
    }
}
