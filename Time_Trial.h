#ifndef ALL_ULTIMO_GAS_TIME_TRIAL_H
#define ALL_ULTIMO_GAS_TIME_TRIAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Control.h"

using namespace sf;
using namespace std;


class Time_Trial {

public:
    Time_Trial();

    bool setTime_TrialState(Texture *T_timetrial, Sprite *S_timetrial);
    int getReturn(double& posx, double& posy);
    int getTime_Racecircuit(double& posx, double& posy, Texture *T_timetrial, Sprite *S_timetrial);
    int getTime_LoadPage(double& posx, double& posy);
    bool Timetrial_LoadPage(Texture *T_timetrial, Sprite *S_timetrial);
    bool End_TimeTrial(Texture &T_Flag, Sprite &S_Flag);
    void getTime_lap(float x_CarPlayer, float y_CarPlayer);
    Time timelap;
    Clock clock_lap;

protected:
    int *Lap_Time_Minutes, *Lap_Time_Seconds, *Lap_Time_Milliseconds, minute_const, best_Minute;
    float Middle_Time;
    int x1_Traguardo, x2_Traguardo, y1_Traguardo, y2_Traguardo, intermediate1=0, intermediate2=0, intermediate3=0;
    int circuit=0, number_of_Lap=0, control_lap=0, i=2;




};


#endif //ALL_ULTIMO_GAS_TIME_TRIAL_H
