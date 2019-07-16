//
// Created by alessio on 17/12/18.
//

#ifndef ALL_ULTIMO_GAS_WEATHER_H
#define ALL_ULTIMO_GAS_WEATHER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"


using namespace std;
using namespace sf;


class Weather {

public:

    Weather();

    void setWeather(int meteo, RenderWindow &window, Error &error);

private:

    int x_rain=0, y_rain=0;
    float sun_degree=0;
    Sprite S_rain[3], S_sun;
    Texture T_rain, T_sun;
    bool control_rain, control_sun;

    void do_Sun(RenderWindow &window, Error &error);
    void do_Rain(RenderWindow &window, Error &error);

};


#endif //ALL_ULTIMO_GAS_WEATHER_H
