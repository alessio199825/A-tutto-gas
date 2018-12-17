//
// Created by alessio on 17/12/18.
//

#ifndef ALL_ULTIMO_GAS_WEATHER_H
#define ALL_ULTIMO_GAS_WEATHER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>


using namespace std;
using namespace sf;


class Weather {

public:
    Weather();

    int x_rain=0, y_rain=0;
    bool set_weather(int meteo, Sprite *S_rain, Texture *T_rain);
    int Rain( Sprite *S_rain, Texture *T_rain);
    int Sun();

};


#endif //ALL_ULTIMO_GAS_WEATHER_H