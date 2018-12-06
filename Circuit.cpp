#include "Circuit.h"

Circuit::Circuit() {}


bool Circuit::setTileMaps(int CircuitOn, Sprite *S_tilemaps, Texture *T_tilemaps, Sprite *S_Pause, Texture *T_Pause) {

    if(!T_Pause[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/race/termina.png")){
        return true;
    }
    S_Pause[0].setTexture(T_Pause[0]);
    switch (CircuitOn) {
        case 1:
            if (!T_tilemaps->loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Single_Race/CIRCUITO_BASE.jpg")) {       //3 giri modificato
                return true;
            }
            S_Pause[0].setPosition(910, 510);
            break;
        case 2:
            if (!T_tilemaps->loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Single_Race/CIRCUITO_MEDIO.png")) {       //3 giri modificato
                return true;
            }
            S_Pause[0].setPosition(20, 510);
            break;
        case 3:
            if (!T_tilemaps->loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Single_Race/CIRCUITO_DIFFICILE.png")) {       //3 giri modificato
                return true;
            }
            S_Pause[0].setPosition(910, 120);
            break;
        default:
            break;
    }
    if(!T_Pause[1].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/race/pausa.png")){
        return true;
    }
    S_Pause[1].setTexture(T_Pause[1]);
    S_Pause[1].setPosition(874, -5);
    S_tilemaps->setTexture(*T_tilemaps);

    return false;
}

int Circuit::getTileMaps() {

    return 0;
}

bool Circuit::setWeather() {
    return false;
}

bool Circuit::getWeather() {
    return false;
}

int Circuit::getTile() {
    return 0;
}

Circuit::~Circuit() {

}


/*


WeatherBehavior::WeatherBehavior() {}

int WeatherBehavior::Do_weather() {
    return 0;
}

Sun::Sun() {}

void Sun::Do_weather() {
    WeatherBehavior::Do_weather();
}

Rain::Rain() {}

void Rain::Do_weather1() {

}


*/
