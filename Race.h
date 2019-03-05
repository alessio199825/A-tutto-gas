#ifndef PROGETTO_RACE_H
#define PROGETTO_RACE_H

#include <SFML/Graphics.hpp>
#include "Circuit.h"
#include "Car.h"
#include "Cars_Cpu.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace sf;

class Race{

public:

    RenderWindow window_Break;
    Event event_Break;
    Texture T_Break;
    Sprite S_Break;

    void setGame(RenderWindow &window, Circuit &circuit, Car &car, Error &error, Cars_Cpu &cars_cpu, int num_circuit);
    void KeyBreak(RenderWindow &window, Error &error, double& posx, double& posy, int &menu_state, int num_circuit, int &stateSwitch);
    float getX_tmp() const;
    float getY_tmp() const;

    Race();

private:

    int loop=0;
    float X_tmp, Y_tmp;

    void End_Game(int num_circuit, double& posx, double& posy, int &stateSwitch);
    int Break(RenderWindow &window, Error &error);

};

#endif