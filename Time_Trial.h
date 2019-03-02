#ifndef ALL_ULTIMO_GAS_TIME_TRIAL_H
#define ALL_ULTIMO_GAS_TIME_TRIAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Control.h"
#include "Car.h"

using namespace sf;
using namespace std;


class Time_Trial {

public:
    Time_Trial();

    Car car;

    bool setTime_TrialState(RenderWindow &window);
    int getReturn(double& posx, double& posy);
    int getTime_Racecircuit(double posx, double posy, RenderWindow &window);
    int getTime_LoadPage(double posx, double posy);
    bool Timetrial_LoadPage(RenderWindow &window);
    bool End_TimeTrial(RenderWindow &window);
    bool getTime_lap(RenderWindow &window);
    bool print_TimeLap(RenderWindow &window);
    bool print_TimeMinute(RenderWindow &window);

    const Sprite getS_timetrial(int i) const;

    Time timelap;
    Clock clock_lap;
    Font F_time;

protected:
    int Lap_Time_Milliseconds[10], minute_const, best_Minute;
    int Lap_Time_Seconds[10];
    int Lap_Time_Minutes[10];
    int x1_Traguardo, x2_Traguardo, y1_Traguardo, y2_Traguardo, intermediate1=0, intermediate2=0, intermediate3=0;
    int circuit=0, number_of_Lap=0, control_lap=0, k=2;

private:

    float X_tmp, Y_tmp;
    Texture T_timetrial[11], T_Flag;
    Sprite S_timetrial[11], S_Flag;
    Text X_time[3], X_time_minute;


};


#endif //ALL_ULTIMO_GAS_TIME_TRIAL_H
