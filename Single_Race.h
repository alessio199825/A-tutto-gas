//
// Created by alessio on 20/10/18.
//

#ifndef ALL_ULTIMO_GAS_SINGLE_RACE_H
#define ALL_ULTIMO_GAS_SINGLE_RACE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Single_Race {


protected:
    int order;
    int circuit;
    int Number_Lap;
    int giri;
    int tempo, Sraceon, circuitrace;
    bool SingleRace_ControlReturn=true;
    Time time_return1, time_return;
    Clock C_return;

public:
    Single_Race();
    int setSingle_RaceState(Texture *T_singlerace, Sprite *S_singlerace);
    int getSingle_RaceReturn(double& posx, double& posy);
    int getSingle_RaceLap(double& posx, double& posy, Texture *T_singlerace, Sprite *S_singlerace);
    int getSingle_RaceWeather(double& posx, double& posy, Texture *T_singlerace, Sprite *S_singlerace);
    int setSingle_RaceState2(Texture *T_singleraceon, Sprite *S_singleraceon);
    int getSingle_Raceon(double& posx, double& posy);
    int getSingle_Raceonreturn(double& posx, double& posy);
    int getSingle_RaceCircuit(double& posx, double& posy, Texture *T_singlerace, Sprite *S_singlerace);
    int getSingle_LoadPage(double& posx, double& posy);
    bool Single_LoadPage(Texture *T_singlerace, Sprite *S_singlerace);
    bool End_SingleRace(Texture &T_Flag, Sprite &S_Flag);


};


#endif //ALL_ULTIMO_GAS_SINGLE_RACE_H
