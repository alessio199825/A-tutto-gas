//
// Created by alessio on 17/12/18.
//

#include "Weather.h"

Weather::Weather() {

}

bool Weather::setWeather(int meteo, Sprite *S_rain, Texture *T_rain, Sprite *S_sun, Texture *T_sun) {
    switch (meteo) {
        case 1:
            do_Sun(S_sun, T_sun);
            return false;
        case 2:
            do_Rain(S_rain, T_rain);
            return true;
        default:break;
    }
    return false;

}

int Weather::do_Rain(Sprite *S_rain, Texture *T_rain) {

    if (!T_rain->loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Weather/pioggia.png")) {
        return -1;
    }

    S_rain[0].setTexture(*T_rain);
    S_rain[0].setPosition(0,y_rain);
    S_rain[1].setTexture(*T_rain);
    S_rain[1].setPosition(x_rain, y_rain-600);
    S_rain[2].setTexture(*T_rain);
    S_rain[2].setPosition(x_rain, y_rain-1200);

    y_rain=y_rain+6;

    if(y_rain==1200){
        y_rain=0;
    }
    return 0;
}

int Weather::do_Sun(Sprite *S_sun, Texture *T_sun) {
    if (!T_sun->loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Weather/sole.png")) {
        return -1;
    }

    S_sun->setTexture(*T_sun);
    S_sun->setOrigin(100,100);
    S_sun->setPosition(0,0);
    S_sun->setRotation(sun_degree);

    sun_degree=sun_degree+1;

    return 0;
}


