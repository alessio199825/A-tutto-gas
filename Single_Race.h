#ifndef ALL_ULTIMO_GAS_SINGLE_RACE_H
#define ALL_ULTIMO_GAS_SINGLE_RACE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace std;
using namespace sf;

class Single_Race {

public:

    Single_Race();

    ~Single_Race();

    void setSingle_RaceState(RenderWindow &window, Error &error);
    int getSingle_RaceReturn(double posx, double posy);
    int getSingle_RaceLap(double posx, double posy, RenderWindow &window, Error &error);
    int getSingle_RaceWeather(double posx, double posy, RenderWindow &window, Error &error);
    void setSingle_RaceState2(RenderWindow &window, Error &error);
    int getSingle_Raceon(double posx, double posy);
    int getSingle_Raceonreturn(double posx, double posy);
    int getSingle_RaceCircuit(double posx, double posy, RenderWindow &window, Error &error);
    int getSingle_LoadPage(double posx, double posy);
    void Single_LoadPage(RenderWindow &window, Error &error);
    void End_SingleRace(RenderWindow &window, Error &error);

private:

    int circuit, tempo, circuitrace, giri;
    bool SingleRace_ControlReturn=true;
    Time time_return1, time_return;
    Clock C_return;
    Texture T_singlerace[16], T_singleraceon[10], T_Flag;
    Sprite S_singlerace[16], S_singleraceon[10], S_Flag;

};


#endif //ALL_ULTIMO_GAS_SINGLE_RACE_H
