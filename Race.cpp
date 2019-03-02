#include "Race.h"
#include <iostream>

Race::Race() {

}

bool Race::setGame(RenderWindow &window, Circuit &circuit, Car &car, Cars_Cpu &cars_cpu, int num_circuit) {

    if(circuit.setTileMaps(window, num_circuit)){
        return true;
    }
    if(car.setMachinePlayer(window, num_circuit)){
        return true;
    }
    if(cars_cpu.createMachine(window)){
        return true;
    }

    X_tmp=car.getX_CarPlayer();
    Y_tmp=car.getY_CarPlayer();

    return false;

}

bool Race::KeyBreak(double& posx, double& posy, int &menu_state, int num_circuit, int &stateSwitch) {       //tasto che richiama la finestra di pausa

        if (posx > 874 && posx < 978 && posy > 19 && posy < 99) {
            switch(Break()){
                case 0:
                    return true;
                case 1:
                    return false;
                case 2:
                    menu_state=0;
                    return false;
                default: break;
            }
        }

        End_Game(num_circuit, posx, posy, stateSwitch);
        return false;
}

int Race::Break() {        //crea la finestra di pausa
    while(loop==0) {
        window_Break.create(VideoMode(500, 300), "Pause");
        while (window_Break.isOpen()) {
            while (window_Break.pollEvent(event_Break)) {
                if (event_Break.type == Event::Closed)
                    window_Break.close();
            }

            if (!T_Break.loadFromFile("race/break.png")) {
                return 0;
            }

            S_Break.setTexture(T_Break);

            if(Mouse::isButtonPressed(Mouse::Left) ) {
                if (Mouse::getPosition(window_Break).x > 118 && Mouse::getPosition(window_Break).x < 195
                        && Mouse::getPosition(window_Break).y > 197 && Mouse::getPosition(window_Break).y < 275) {
                    window_Break.close();
                    return 1;
                }

                if (Mouse::getPosition(window_Break).x> 279 && Mouse::getPosition(window_Break).x < 357 &&
                    Mouse::getPosition(window_Break).y > 197 && Mouse::getPosition(window_Break).y < 275) {
                    window_Break.close();
                    return 2;
            }
            }

            window_Break.clear();
            window_Break.draw(S_Break);
            window_Break.display();
        }
    }
}

void Race::End_Game(int num_circuit, double &posx, double &posy, int &Race_state) {       //tasto termina gara
    switch(num_circuit){
        case 1:
            if (posx > 910 && posx < 980 && posy > 510 && posy < 580) {
                Race_state++;
            }
        break;
        case 2:
            if (posx > 20 && posx < 90 && posy > 510 && posy < 580)
                Race_state++;
        break;
        case 3:
            if (posx > 910 && posx < 980 && posy > 120 && posy < 190)
                Race_state++;
        break;
        default: break;
    }
}

bool Qualifications::Do_qualifications() {
    return false;
}

void Qualifications::setQualificationsState(int) {

}

int Qualifications::getRace() {
    return 0;
}

Qualifications::Qualifications() {

}

void Race::DO_race(int) {

}

void Race::setRaceState(int) {

}

int Race::getChampionship() {
    return 0;
}

int Race::getTime_trial() {
    return 0;
}

int Race::getSingle_race() {
    return 0;
}

float Race::getX_tmp() const {
    return X_tmp;
}

float Race::getY_tmp() const {
    return Y_tmp;
}



