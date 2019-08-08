//
// Created by alessio on 16/03/19.
//

#include "SingleRace_Page2.h"
#include "SingleRace_Page.h"
#include "Load_Page.h"
#include "Load_Exception.h"

SingleRace_Page2::SingleRace_Page2(RenderWindow &window, Error &error, int weath, int lap) {

    setWindow(error, window);
    meteo=weath;
    giri=lap;
    circuitrace=0;
}

SingleRace_Page2::~SingleRace_Page2() = default;

void SingleRace_Page2::draw(RenderWindow &window) {

    for(int i=0; i<7; i++){
        window.draw(S_singleraceon[i]);
    }

    switch (circuitrace) {
        case 1:
            window.draw(S_singleraceon[7]);
            break;
        case 2:
            window.draw(S_singleraceon[8]);
            break;
        case 3:
            window.draw(S_singleraceon[9]);
            break;
        default:
            break;
    }

}

int SingleRace_Page2::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;

                case Keyboard::BackSpace:                         //con il tasto Return torniamo al SingleRace_Page
                    pageIndex = 2;
                    pageChanged=true;
                    break;
                default:
                    break;
            }
            break;
        case Event::MouseButtonReleased:

            if (Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 920 &&
                Mouse::getPosition(window).y > 290 && Mouse::getPosition(window).y < 360) {             //tasto avanti
                pageIndex = 9;
                pageChanged=true;
                Type_race=2;
            }

            if (Mouse::getPosition(window).x > 25 && Mouse::getPosition(window).x < 125 &&
                Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 115) {
                pageIndex = 2;
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

            break;
        default:
            break;
    }

    return 0;

}

void SingleRace_Page2::setWindow(Error &error, RenderWindow &window) {

    try {

        if (!T_singleraceon[0].loadFromFile("Single_Race/gara singola.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[0].setTexture(T_singleraceon[0]);

        if (!T_singleraceon[1].loadFromFile("Single_Race/indietro.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[1].setTexture(T_singleraceon[1]);
        S_singleraceon[1].setPosition(sf::Vector2f(25, 25));

        if (!T_singleraceon[2].loadFromFile("Single_Race/seleziona circuito.png")) {       //scritta scegli circuito
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[2].setTexture(T_singleraceon[2]);
        S_singleraceon[2].setPosition(sf::Vector2f(50, 290));

        if (!T_singleraceon[3].loadFromFile("Single_Race/avanti.png")) {       //scritta avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[3].setTexture(T_singleraceon[3]);
        S_singleraceon[3].setPosition(sf::Vector2f(600, 290));

        if (!T_singleraceon[4].loadFromFile("Single_Race/circuit2.jpg")) {       //circuito1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[4].setTexture(T_singleraceon[4]);
        S_singleraceon[4].setPosition(sf::Vector2f(50, 390));

        if (!T_singleraceon[5].loadFromFile("Single_Race/circuit1-1.jpg")) {       //circuito 2
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[5].setTexture(T_singleraceon[5]);
        S_singleraceon[5].setPosition(sf::Vector2f(350, 390));

        if (!T_singleraceon[6].loadFromFile("Single_Race/circuit3-1.jpg")) {       //circuito 3
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[6].setTexture(T_singleraceon[6]);
        S_singleraceon[6].setPosition(sf::Vector2f(650, 390));


        if (!T_singleraceon[7].loadFromFile("Single_Race/circuit2on.jpg")) {       //circuito 1 modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singleraceon[7].setTexture(T_singleraceon[7]);
        S_singleraceon[7].setPosition(sf::Vector2f(50, 390));

        if (!T_singleraceon[8].loadFromFile("Single_Race/circuit1on.jpg")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }

        S_singleraceon[8].setTexture(T_singleraceon[8]);
        S_singleraceon[8].setPosition(sf::Vector2f(350, 390));

        if (!T_singleraceon[9].loadFromFile("Single_Race/circuit3on.jpg")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }

        S_singleraceon[9].setTexture(T_singleraceon[9]);
        S_singleraceon[9].setPosition(sf::Vector2f(650, 390));

    }
    catch(Load_exception e){
        error.Check_Image(window);
    }

}

Menu_State *SingleRace_Page2::getNewPage(RenderWindow &window, Error &error) {
    switch(pageIndex) {
        case 2:
            return new SingleRace_Page(window, error);
        case 9:
            return new Load_Page(window, error, circuitrace, Type_race, meteo, giri, chooseCar);
        default:break;
    }
}

