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

    bool setWeather(int meteo, RenderWindow &window);

    const Sprite getS_rain(int i) const;

    const Sprite getS_sun() const;

    int do_Sun(RenderWindow &window);

private:

    int x_rain=0, y_rain=0, sun_degree=0;
    Sprite S_rain[3], S_sun;
    Texture T_rain, T_sun;

    int do_Rain(RenderWindow &window);


};


#endif //ALL_ULTIMO_GAS_WEATHER_H
