//
// Created by alessio on 08/08/19.
//

#include "Flag_Page.h"
#include "Load_Exception.h"
#include "Menu_Game.h"
#include "Load_Page.h"

Flag_Page::Flag_Page(RenderWindow &window, Error &error, int Type_race, int chooseCar, int numcircuit, int position_car, int position_cpu[5]) {
    posizione_macchina = position_car;
    for(int i = 0; i<5; i++){
        posizione_pc[i] = position_cpu[i];
    }
    setWindow(error, window);
    CircuitNum=numcircuit;
    Race_type=Type_race;
    choosecar = chooseCar;
}

Flag_Page::~Flag_Page() = default;

void Flag_Page::draw(RenderWindow &window) {

    for(int i=0; i<9; i++)
        window.draw(S_Flag[i]);

    if(Race_type==1)
        window.draw(S_Flag[9]);

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

            if(Race_type==1) {
                if (Mouse::getPosition(window).x > 340 && Mouse::getPosition(window).x < 660 &&
                    Mouse::getPosition(window).y > 485 && Mouse::getPosition(window).y < 555) {
                    pageIndex = 9;
                    pageChanged = true;
                }
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

    switch(posizione_macchina){
        case 1:
            y_flag[5]=120;
            break;
        case 2:
            y_flag[5]=170;
            break;
        case 3:
            y_flag[5]=220;
            break;
        case 4:
            y_flag[5]=270;
            break;
        case 5:
            y_flag[5]=320;
            break;
        case 6:
            y_flag[5]=370;
            break;
        default:break;
    }

    for(int i=0; i<5; i++){
        switch(posizione_pc[i]){
            case 1:
                y_flag[i]=120;
                break;
            case 2:
                y_flag[i]=170;
                break;
            case 3:
                y_flag[i]=220;
                break;
            case 4:
                y_flag[i]=270;
                break;
            case 5:
                y_flag[i]=320;
                break;
            case 6:
                y_flag[i]=370;
                break;
            default:break;
        }
    }

    try {
        if (!T_Flag[0].loadFromFile("race/scacchi.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[0].setTexture(T_Flag[0]);

        if (!T_Flag[1].loadFromFile("race/menu.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[1].setTexture(T_Flag[1]);
        S_Flag[1].setPosition(sf::Vector2f(708, 25));

        if (!T_Flag[2].loadFromFile("race/player.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[2].setTexture(T_Flag[2]);
        S_Flag[2].setPosition(sf::Vector2f(203, y_flag[5]));

        if (!T_Flag[3].loadFromFile("race/alfonso.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[3].setTexture(T_Flag[3]);
        S_Flag[3].setPosition(sf::Vector2f(203, y_flag[0]));

        if (!T_Flag[4].loadFromFile("race/amilton.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[4].setTexture(T_Flag[4]);
        S_Flag[4].setPosition(sf::Vector2f(203, y_flag[1]));

        if (!T_Flag[5].loadFromFile("race/fettel.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[5].setTexture(T_Flag[5]);
        S_Flag[5].setPosition(sf::Vector2f(203, y_flag[2]));

        if (!T_Flag[6].loadFromFile("race/verstapen.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[6].setTexture(T_Flag[6]);
        S_Flag[6].setPosition(sf::Vector2f(203, y_flag[3]));

        if (!T_Flag[7].loadFromFile("race/ulkemberg.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[7].setTexture(T_Flag[7]);
        S_Flag[7].setPosition(sf::Vector2f(203, y_flag[4]));

        if (!T_Flag[8].loadFromFile("race/classifica.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[8].setTexture(T_Flag[8]);
        S_Flag[8].setPosition(sf::Vector2f(100, 120));

        if (!T_Flag[9].loadFromFile("Single_Race/avanti.png")) {         //pulsante avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag[9].setTexture(T_Flag[9]);
        S_Flag[9].setPosition(sf::Vector2f(240, 485));

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
                CircuitNum++;
                if(CircuitNum==4)
                    return new Flag_Page(window, error, Race_type, choosecar, CircuitNum, posizione_macchina, &posizione_pc[0]);
                if(CircuitNum>4)
                    return new Menu_Game(window, error);

                return new Load_Page(window, error, CircuitNum, Race_type, 0, 3, choosecar);
        default: break;
    }

    return 0;

}
