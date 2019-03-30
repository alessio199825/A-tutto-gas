#include "Race.h"
#include <iostream>

Race::Race() {

}

void Race::setGame(RenderWindow &window, Circuit &circuit, Car &car, Error &error, Cars_Cpu &cars_cpu, int Type_race,
                   int circuitrace) {
    circuit.setTileMaps(circuitrace, error, window);

    car.setMachinePlayer(window, circuitrace, error, Type_race);

    cars_cpu.createMachine(window, error);

    X_tmp=car.getX_CarPlayer();
    Y_tmp=car.getY_CarPlayer();

}

void Race::KeyBreak(RenderWindow &window, Error &error, Song &song, double &posx, double &posy, int &pageIndex,
                    bool &pageChanged, int circuitrace) {       //tasto che richiama la finestra di pausa

        if (posx > 874 && posx < 978 && posy > 19 && posy < 99) {
            song.pause_Race(true);
            song.Music_RadioPause(true);
            if(Break(window, error, song)==2) {
                pageIndex = 0;
                pageChanged = true;
            }
        }
    End_Game(posx, posy, pageIndex, circuitrace);
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
                    throw "impossibile caricare Texture";
                }
            }
            catch(...){
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

void Race::End_Game(double &posx, double &posy, int &pageIndex, int circuitrace) {       //tasto termina gara
    switch(circuitrace){
        case 1:
            if (posx > 910 && posx < 980 && posy > 510 && posy < 580)
                pageIndex++;
        break;
        case 2:
            if (posx > 20 && posx < 90 && posy > 510 && posy < 580)
                pageIndex++;
        break;
        case 3:
            if (posx > 910 && posx < 980 && posy > 120 && posy < 190)
                pageIndex++;
        break;
        default: break;
    }
}

float Race::getX_tmp() const {
    return X_tmp;
}

float Race::getY_tmp() const {
    return Y_tmp;
}






