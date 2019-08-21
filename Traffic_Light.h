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
#include "Song.h"

using namespace sf;
using namespace std;

class Traffic_Light {

public:
    Traffic_Light();

    Song song;

    bool Light_On(RenderWindow &window, Error &error, int Type_race);

    void setControl_light(bool control_light);

private:
    Texture T_Light[7];
    Sprite S_Light[7];
    Clock light_clock;
    Time light_time;
    bool control_light=true, control_trafficlight;
};


#endif //ALL_ULTIMO_GAS_TRAFFIC_LIGHT_H
