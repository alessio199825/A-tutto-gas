#include "Circuit.h"
#include "Load_Exception.h"

Circuit::Circuit() = default;

void Circuit::setTileMaps(int circuitrace, Error &error, RenderWindow &window, int Type_race) {

    try {

            if (!T_Pause[0].loadFromFile("race/termina.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }

            S_Pause[0].setTexture(T_Pause[0]);

            switch (circuitrace) {
                case 1:
                    if (!T_tilemaps.loadFromFile("Single_Race/CIRCUITO_BASE.jpg")) {       //3 giri modificato
                        throw Load_exception("Load_exception:Impossibile caricare file");
                    }
                    S_Pause[0].setPosition(910, 510);
                    break;
                case 2:
                    if (!T_tilemaps.loadFromFile("Single_Race/CIRCUITO_MEDIO.jpg")) {       //3 giri modificato
                        throw Load_exception("Load_exception:Impossibile caricare file");
                    }
                    S_Pause[0].setPosition(20, 510);
                    break;
                case 3:
                    if (!T_tilemaps.loadFromFile("Single_Race/CIRCUITO_DIFFICILE.jpg")) {       //3 giri modificato
                        throw Load_exception("Load_exception:Impossibile caricare file");
                    }
                    S_Pause[0].setPosition(910, 120);
                    break;
                default:
                    break;

            }
        if (!T_Pause[1].loadFromFile("race/pausa.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
    }

    S_Pause[1].setTexture(T_Pause[1]);
    S_Pause[1].setPosition(874, -5);
    S_tilemaps.setTexture(T_tilemaps);
    window.draw(S_tilemaps);
    window.draw(S_Pause[0]);
    window.draw(S_Pause[1]);
}

Circuit::~Circuit() = default;

const Sprite Circuit::getS_tilemaps() const {
    return S_tilemaps;
}

const Sprite Circuit::getS_Pause(int i) const {
    return S_Pause[i];
}
