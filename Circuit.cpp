#include "Circuit.h"
Circuit::Circuit() {}
bool Circuit::setTileMaps(RenderWindow &window, int CircuitOn) {


    if(!T_Pause[0].loadFromFile("race/termina.png")){
        return true;
    }
    S_Pause[0].setTexture(T_Pause[0]);
    switch (CircuitOn) {
        case 1:
            if (!T_tilemaps.loadFromFile("Single_Race/CIRCUITO_BASE.jpg")) {       //3 giri modificato
                return true;
            }
            S_Pause[0].setPosition(910, 510);
            break;
        case 2:
            if (!T_tilemaps.loadFromFile("Single_Race/CIRCUITO_MEDIO.png")) {       //3 giri modificato
                return true;
            }
            S_Pause[0].setPosition(20, 510);
            break;
        case 3:
            if (!T_tilemaps.loadFromFile("Single_Race/CIRCUITO_DIFFICILE.png")) {       //3 giri modificato
                return true;
            }
            S_Pause[0].setPosition(910, 120);
            break;
        default:
            break;
    }
    if(!T_Pause[1].loadFromFile("race/pausa.png")){
        return true;
    }
    S_Pause[1].setTexture(T_Pause[1]);
    S_Pause[1].setPosition(874, -5);
    S_tilemaps.setTexture(T_tilemaps);
    window.draw(S_tilemaps);
    window.draw(S_Pause[0]);
    window.draw(S_Pause[1]);
    return false;
}
int Circuit::getTileMaps() {
    return 0;
}

int Circuit::getTile() {
    return 0;
}
Circuit::~Circuit() {
}

const Sprite Circuit::getS_tilemaps() const {
    return S_tilemaps;
}

const Sprite Circuit::getS_Pause(int i) const {
    return S_Pause[i];
}
