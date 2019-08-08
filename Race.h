#ifndef PROGETTO_RACE_H
#define PROGETTO_RACE_H

#include <SFML/Graphics.hpp>
#include "Circuit.h"
#include "Car.h"
#include "Cars_Cpu.h"
#include "Song.h"
#include <iostream>
#include <cstring>
#include "Menu_State.h"

using namespace std;
using namespace sf;

class Race{

public:

    RenderWindow window_Break;
    Event event_Break;
    Texture T_Break;
    Sprite S_Break;
    Song song;

    void setGame(RenderWindow &window, Circuit &circuit, Car &car, Error &error, int Type_race, int circuitrace, int chooseCar);
    void KeyBreak(RenderWindow &window, Error &error, Song &song, double &posx, double &posy, int &pageIndex,
                      bool &pageChanged);
    float getX_tmp() const;
    float getY_tmp() const;

    Race();


private:

    int loop=0;
    float X_tmp, Y_tmp;

    int Break(RenderWindow &window, Error &error, Song &song);


};

#endif