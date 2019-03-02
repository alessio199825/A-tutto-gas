#include "Single_Race.h"


Single_Race::Single_Race() = default;


bool Single_Race::setSingle_RaceState(RenderWindow &window) {

        time_return1=C_return.getElapsedTime();
        if (!T_singlerace[0].loadFromFile("Single_Race/gara singola.png")) {
                return true;
        }
        S_singlerace[0].setTexture(T_singlerace[0]);

        if (!T_singlerace[1].loadFromFile("Single_Race/indietro.jpg")) {       //pulsante1
                return true;
        }
        S_singlerace[1].setTexture(T_singlerace[1]);
        S_singlerace[1].setPosition(sf::Vector2f(25, 25));

        if (!T_singlerace[2].loadFromFile("Single_Race/numero di giri.png")) {       //scritta numero giri
                return true;
        }
        S_singlerace[2].setTexture(T_singlerace[2]);
        S_singlerace[2].setPosition(sf::Vector2f(50, 200));

        if (!T_singlerace[3].loadFromFile("Single_Race/ok3.jpg")) {       //3 giri
                return true;
        }
        S_singlerace[3].setTexture(T_singlerace[3]);
        S_singlerace[3].setPosition(sf::Vector2f(50, 300));

        if (!T_singlerace[4].loadFromFile("Single_Race/ok5.jpg")) {       //5 giri
                return true;
        }
        S_singlerace[4].setTexture(T_singlerace[4]);
        S_singlerace[4].setPosition(sf::Vector2f(159, 300));

        if (!T_singlerace[5].loadFromFile("Single_Race/ok10.jpg")) {       //10 giri
                return true;
        }
        S_singlerace[5].setTexture(T_singlerace[5]);
        S_singlerace[5].setPosition(sf::Vector2f(268, 300));

        if (!T_singlerace[6].loadFromFile("Single_Race/meteo.png")) {       //meteo
                return true;
        }
        S_singlerace[6].setTexture(T_singlerace[6]);
        S_singlerace[6].setPosition(sf::Vector2f(50, 420));

        if (!T_singlerace[7].loadFromFile("Single_Race/sole.jpg")) {       //sole
                return true;
        }
        S_singlerace[7].setTexture(T_singlerace[7]);
        S_singlerace[7].setPosition(sf::Vector2f(389, 420));

        if (!T_singlerace[8].loadFromFile("Single_Race/pioggia.jpg")) {       //pioggia
                return true;
        }
        S_singlerace[8].setTexture(T_singlerace[8]);
        S_singlerace[8].setPosition(sf::Vector2f(495, 420));

        if (!T_singlerace[9].loadFromFile("Single_Race/avanti1.png")) {       //avanti
                return true;
        }
        S_singlerace[9].setTexture(T_singlerace[9]);
        S_singlerace[9].setPosition(sf::Vector2f(600, 25));

        if(time_return1.asSeconds()-time_return.asSeconds()>0.5)
        SingleRace_ControlReturn=true;

        for (int i = 0; i < 10; i++) {
                window.draw(S_singlerace[i]);
        }

        return false;
}

int Single_Race::getSingle_RaceLap(double posx, double posy, RenderWindow &window) {

        if (posx > 50 && posx < 139 && posy > 300 && posy < 384) {      //tasto 3 giri

                if (!T_singlerace[10].loadFromFile("Single_Race/ok3on.jpg")) {       //3 giri modificato
                        return 1;
                }
                S_singlerace[10].setTexture(T_singlerace[10]);
                S_singlerace[10].setPosition(sf::Vector2f(50, 300));
                giri=3;
        }

        if (posx > 159 && posx < 248 && posy > 300 && posy < 384) {             //tasto 5 giri

                if (!T_singlerace[11].loadFromFile("Single_Race/ok5on.jpg")) {       //5 giri modificato
                        return 1;
                }
                S_singlerace[11].setTexture(T_singlerace[11]);
                S_singlerace[11].setPosition(sf::Vector2f(159, 300));
                giri=5;
        }

        if (posx > 268 && posx < 357 && posy > 300 && posy < 384) {            //tasto 10 giri

                if (!T_singlerace[12].loadFromFile("Single_Race/ok10on.jpg")) {       //10 giri modificato
                        return 1;
                }
                S_singlerace[12].setTexture(T_singlerace[12]);
                S_singlerace[12].setPosition(sf::Vector2f(268, 300));
                giri=10;

        }

        switch (giri) {
                case 3:
                        window.draw(S_singlerace[10]);
                break;
                case 5:
                        window.draw(S_singlerace[11]);
                break;
                case 10:
                        window.draw(S_singlerace[12]);
                break;
                default:
                        break;
        }
        return giri;
}

int Single_Race::getSingle_RaceReturn(double posx, double posy) {
        if (posx > 25 && posx < 125 && posy > 25 && posy < 115 && SingleRace_ControlReturn) {
                return 0;
        }
        return 2;
}

int Single_Race::getSingle_RaceWeather(double posx, double posy, RenderWindow &window) {
        if (posx > 389 && posx < 475 && posy > 420 && posy < 509) {     //tasto sole

                if (!T_singlerace[13].loadFromFile("Single_Race/soleon.jpg")) {       //sole modificato
                        return -1;
                }
                S_singlerace[13].setTexture(T_singlerace[13]);
                S_singlerace[13].setPosition(sf::Vector2f(389, 420));
                tempo=1;
        }

        if (posx > 495 && posx < 581 && posy > 420 && posy < 509) {      //tasto pioggia

                if (!T_singlerace[14].loadFromFile("Single_Race/pioggia on.jpg")) {       //pioggia modificato
                        return -1;
                }
                S_singlerace[14].setTexture(T_singlerace[14]);
                S_singlerace[14].setPosition(sf::Vector2f(495, 420));
                tempo=2;
        }

        switch (tempo) {
                case 1:
                        window.draw(S_singlerace[13]);
                break;
                case 2:
                        window.draw(S_singlerace[14]);
                break;
                default:
                        break;
        }
        return tempo;
}

bool Single_Race::setSingle_RaceState2(RenderWindow &window) {

        if (!T_singleraceon[0].loadFromFile("Single_Race/gara singola.png")) {
                return true;
        }
        S_singleraceon[0].setTexture(T_singleraceon[0]);

        if (!T_singleraceon[1].loadFromFile("Single_Race/indietro.jpg")) {       //pulsante1
                return true;
        }
        S_singleraceon[1].setTexture(T_singleraceon[1]);
        S_singleraceon[1].setPosition(sf::Vector2f(25, 25));

        if (!T_singleraceon[2].loadFromFile("Single_Race/seleziona circuito.png")) {       //scritta scegli circuito
                return true;
        }
        S_singleraceon[2].setTexture(T_singleraceon[2]);
        S_singleraceon[2].setPosition(sf::Vector2f(50, 290));

        if (!T_singleraceon[3].loadFromFile("Single_Race/avanti.png")) {       //scritta avanti
                return true;
        }
        S_singleraceon[3].setTexture(T_singleraceon[3]);
        S_singleraceon[3].setPosition(sf::Vector2f(600, 290));

        if (!T_singleraceon[4].loadFromFile("Single_Race/circuit2.jpg")) {       //circuito1
                return true;
        }
        S_singleraceon[4].setTexture(T_singleraceon[4]);
        S_singleraceon[4].setPosition(sf::Vector2f(50, 390));

        if (!T_singleraceon[5].loadFromFile("Single_Race/circuit1-1.jpg")) {       //circuito 2
                return true;
        }
        S_singleraceon[5].setTexture(T_singleraceon[5]);
        S_singleraceon[5].setPosition(sf::Vector2f(350, 390));

        if (!T_singleraceon[6].loadFromFile("Single_Race/circuit3-1.jpg")) {       //circuito 3
                return true;
        }
        S_singleraceon[6].setTexture(T_singleraceon[6]);
        S_singleraceon[6].setPosition(sf::Vector2f(650, 390));

        for (int i = 0; i < 7; i++) {
                window.draw(S_singleraceon[i]);
        }
        return false;
}

int Single_Race::getSingle_Raceon(double posx, double posy) {

        if (posx > 600 && posx < 920 && posy > 25 && posy < 115) {             //tasto avanti
                return 1;
        }
        return 0;
}

int Single_Race::getSingle_Raceonreturn(double posx, double posy) {
        if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
                SingleRace_ControlReturn=false;
                time_return=C_return.getElapsedTime();
                return 0;
        }
        return 1;
}

int Single_Race::getSingle_RaceCircuit(double posx, double posy, RenderWindow &window) {
        if (posx > 50 && posx < 310 && posy > 390 && posy < 585) { //tasto circuito 1

                if (!T_singleraceon[7].loadFromFile("Single_Race/circuit2on.jpg")) {       //circuito 1 modificato
                        return -1;
                }
                S_singleraceon[7].setTexture(T_singleraceon[7]);
                S_singleraceon[7].setPosition(sf::Vector2f(50, 390));
                circuitrace=1;
        }


        if (posx > 350 && posx < 610 && posy > 390 && posy < 585) {     //tasto circuito 2

                if (!T_singleraceon[8].loadFromFile("Single_Race/circuit1on.jpg")) {
                        return -1;
                }

                S_singleraceon[8].setTexture(T_singleraceon[8]);
                S_singleraceon[8].setPosition(sf::Vector2f(350, 390));
                circuitrace=2;
        }

        if (posx > 650 && posx < 910 && posy > 390 && posy < 585) {     //tasto circuito 3

                if (!T_singleraceon[9].loadFromFile("Single_Race/circuit3on.jpg")) {
                        return -1;
                }

                S_singleraceon[9].setTexture(T_singleraceon[9]);
                S_singleraceon[9].setPosition(sf::Vector2f(650, 390));

                circuitrace=3;
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
        return circuitrace;

}

bool Single_Race::Single_LoadPage(RenderWindow &window) {

        if (!T_singlerace[15].loadFromFile("Single_Race/planisfero.png")) {       //pulsante1
                return true;
        }
        S_singlerace[15].setTexture(T_singlerace[15]);

        window.draw(S_singlerace[15]);

        return false;
}

int Single_Race::getSingle_LoadPage(double posx, double posy) {

        if (posx > 600 && posx < 920 && posy > 290 && posy < 360) {             //tasto avanti
            return 2;
        }
        return 1;
}

bool Single_Race::End_SingleRace(RenderWindow &window) {

        if (!T_Flag.loadFromFile("race/scacchi.jpg")) {       //pulsante1
                return true;
        }
        S_Flag.setTexture(T_Flag);

        window.draw(S_Flag);

        return false;
}

const Sprite Single_Race::getS_singlerace(int i) const {
    return S_singlerace[i];
}

const Sprite Single_Race::getS_singleraceon(int i) const {
    return S_singleraceon[i];
}

Single_Race::~Single_Race() = default;


