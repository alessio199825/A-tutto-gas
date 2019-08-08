#include "Race.h"
#include "Load_Exception.h"
#include <iostream>

Race::Race() = default;

void Race::setGame(RenderWindow &window, Circuit &circuit, Car &car, Error &error, int Type_race, int circuitrace, int chooseCar) {

    circuit.setTileMaps(circuitrace, error, window, Type_race);

    car.setMachinePlayer(window, circuitrace, error, Type_race, chooseCar);

    X_tmp=car.getX_CarPlayer();
    Y_tmp=car.getY_CarPlayer();

}

void Race::KeyBreak(RenderWindow &window, Error &error, Song &song, double &posx, double &posy, int &pageIndex,
                    bool &pageChanged) {       //tasto che richiama la finestra di pausa

        if(Mouse::isButtonPressed(Mouse::Left) ) {
            if (Mouse::getPosition(window).x  > 874 && Mouse::getPosition(window).x  < 978
                    && Mouse::getPosition(window).y  > 19 && Mouse::getPosition(window).y < 99) {
                song.pause_Race(true);
                song.Music_RadioPause(true);
                if (Break(window, error, song) == 2) {
                    pageIndex = 0;
                    pageChanged = true;
                }
            }
        }
}

int Race::Break(RenderWindow &window, Error &error, Song &song) {        //crea la finestra di pausa
    while(loop==0) {
        window_Break.create(VideoMode(500, 300), "Pause");
                while (window_Break.isOpen()) {
            while (window_Break.pollEvent(event_Break)) {
                if (event_Break.type == Event::Closed)
                    window_Break.close();
            }

            try {
                if (!T_Break.loadFromFile("race/break.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
            }
            catch(Load_exception e){
                window.close();
                error.Check_Image(window);
            }

            S_Break.setTexture(T_Break);

            if(Mouse::isButtonPressed(Mouse::Left) ) {
                if (Mouse::getPosition(window_Break).x > 118 && Mouse::getPosition(window_Break).x < 195
                        && Mouse::getPosition(window_Break).y > 197 && Mouse::getPosition(window_Break).y < 275) {
                    window_Break.close();
                    song.pause_Race(false);
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

float Race::getX_tmp() const {
    return X_tmp;
}

float Race::getY_tmp() const {
    return Y_tmp;
}






