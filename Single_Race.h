#ifndef ALL_ULTIMO_GAS_SINGLE_RACE_H
#define ALL_ULTIMO_GAS_SINGLE_RACE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Single_Race {




public:
    Single_Race();

    ~Single_Race();

    bool setSingle_RaceState();
    int getSingle_RaceReturn(double posx, double posy);
    int getSingle_RaceLap(double posx, double posy);
    int getSingle_RaceWeather(double posx, double posy);
    bool setSingle_RaceState2();
    int getSingle_Raceon(double posx, double posy);
    int getSingle_Raceonreturn(double posx, double posy);
    int getSingle_RaceCircuit(double posx, double posy);
    int getSingle_LoadPage(double posx, double posy);
    bool Single_LoadPage();
    bool End_SingleRace(Texture &T_Flag, Sprite &S_Flag);

    const Sprite getS_singlerace(int i) const;

    const Sprite getS_singleraceon(int i) const;


protected:
    int order;
    int circuit;
    int Number_Lap;
    int giri;
    int tempo, Sraceon, circuitrace;
    bool SingleRace_ControlReturn=true;
    Time time_return1, time_return;
    Clock C_return;

private:
    Texture T_singlerace[16], T_singleraceon[10];
    Sprite S_singlerace[16], S_singleraceon[10];

};


#endif //ALL_ULTIMO_GAS_SINGLE_RACE_H
