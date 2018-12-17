//
// Created by alessio on 17/12/18.
//

#include "Weather.h"

Weather::Weather() {

}

bool Weather::set_weather(int meteo, Sprite *S_rain, Texture *T_rain) {
    switch (meteo) {
        case 1:
            Sun();
            break;
        case 2:
            Rain(S_rain, T_rain);
            return true;
        default:
            break;
    }

}

int Weather::Rain(Sprite *S_rain, Texture *T_rain) {

    if (!T_rain[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Weather/pioggia.png")) {
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

}

int Weather::Sun() {

}


