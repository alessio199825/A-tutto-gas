//
// Created by alessio on 05/03/19.
//

#ifndef ALL_ULTIMO_GAS_TRAFFIC_LIGHT_H
#define ALL_ULTIMO_GAS_TRAFFIC_LIGHT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;
using namespace std;

class Traffic_Light {

public:
    Traffic_Light();

    bool Light_On(RenderWindow &window, Error &error);

    void setControl_light(bool control_light);

private:
    Texture T_Light[6];
    Sprite S_Light[6];
    Clock light_clock;
    Time light_time;
    bool control_light=true;
};


#endif //ALL_ULTIMO_GAS_TRAFFIC_LIGHT_H