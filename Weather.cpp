//
// Created by alessio on 17/12/18.
//

#include "Weather.h"

Weather::Weather() {

}

void Weather::setWeather(int meteo, RenderWindow &window, Error &error) {
    switch (meteo) {
        case 2:
            do_Rain(window, error);
            break;
        default:
            do_Sun(window, error);
            break;
    }
}

void Weather::do_Rain(RenderWindow &window, Error &error) {

    try {
        if (!T_rain.loadFromFile("Weather/pioggia.png")) {
            throw "impossibile caricare Texture";
        }
    }
    catch (...) {
        window.close();
        error.Check_Image();
    }

    S_rain[0].setTexture(T_rain);
    S_rain[0].setPosition(0,y_rain);
    S_rain[1].setTexture(T_rain);
    S_rain[1].setPosition(x_rain, y_rain-600);
    S_rain[2].setTexture(T_rain);
    S_rain[2].setPosition(x_rain, y_rain-1200);

    y_rain=y_rain+6;

    if(y_rain==1200){
        y_rain=0;
    }
    window.draw(S_rain[0]);
    window.draw(S_rain[1]);
    window.draw(S_rain[2]);
}

void Weather::do_Sun(RenderWindow &window, Error &error) {

    try {
        if (!T_sun.loadFromFile("Weather/sole.png")) {
            throw "impossibile caricare Texture";
        }
    }
    catch (...) {
        window.close();
        error.Check_Image();
    }

    S_sun.setTexture(T_sun);
    S_sun.setOrigin(100,100);
    S_sun.setPosition(0,0);
    S_sun.setRotation(sun_degree);

    sun_degree=sun_degree+1;

    window.draw(S_sun);

}


