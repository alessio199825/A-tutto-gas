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

protected:
        int loop=0;
        int Starter_order;
        int Final_order;

public:

        RenderWindow window_Break;
        Event event_Break;
        Texture T_Break;
        Sprite S_Break;
        bool setGame(RenderWindow &window, Circuit &circuit, Car &car, Cars_Cpu &cars_cpu, int num_circuit);
        bool KeyBreak(double& posx, double& posy, int &menu_state, int num_circuit, int &stateSwitch);
        int Break();
        void End_Game(int num_circuit, double& posx, double& posy, int &stateSwitch);
        void DO_race (int);
        void setRaceState (int);
        int getChampionship();
        int getTime_trial();
        int getSingle_race();

    float getX_tmp() const;

    float getY_tmp() const;

    Race();

private:
    float X_tmp, Y_tmp;

};

class Qualifications{

protected:
    int order;
    int Race;

public:
    bool Do_qualifications();
    void setQualificationsState(int);
    int getRace();

    Qualifications();

};

#endif