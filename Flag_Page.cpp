//
// Created by alessio on 08/08/19.
//

#include "Flag_Page.h"
#include "Load_Exception.h"
#include "Menu_Game.h"
#include "Load_Page.h"

Flag_Page::Flag_Page(RenderWindow &window, Error &error, int circuitrace, int Type_race) {
    setWindow(error, window);
    num_circuit=circuitrace;
    Race_type=Type_race;
}

Flag_Page::~Flag_Page() = default;

void Flag_Page::draw(RenderWindow &window) {

    for(int i=0; i<3; i++)
        window.draw(S_Flag[i]);

}

int Flag_Page::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;

            }
            break;
        case Event::MouseButtonReleased:

            if (Mouse::getPosition(window).x > 340 && Mouse::getPosition(window).x < 660 &&
                    Mouse::getPosition(window).y > 485 && Mouse::getPosition(window).y < 555) {
                pageIndex = 9;
                pageChanged = true;
            }

            if (Mouse::getPosition(window).x > 708 && Mouse::getPosition(window).x < 925 &&
                    Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 95) {
                pageIndex = 0;
                pageChanged = true;
            }
            break;
        default:
            break;
    }

    return 0;

}

void Flag_Page::setWindow(Error &error, RenderWindow &window) {

    try {
        if (!T_Flag[0].loadFromFile("race/scacchi.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[0].setTexture(T_Flag[0]);

        if (!T_Flag[1].loadFromFile("Single_Race/avanti.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[1].setTexture(T_Flag[1]);
        S_Flag[1].setPosition(sf::Vector2f(340, 485));


        if (!T_Flag[2].loadFromFile("race/menu.png")){         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[2].setTexture(T_Flag[2]);
        S_Flag[2].setPosition(sf::Vector2f(708, 25));
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
    }

}

Menu_State *Flag_Page::getNewPage(RenderWindow &window, Error &error) {     //punto critico per championship

    switch(pageIndex){
        case 0:
                return new Menu_Game(window, error);
        case 9:
                return new Load_Page(window, error, 1, 2, 2, 5);
        default: break;
    }

    return 0;

}
