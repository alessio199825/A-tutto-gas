//
// Created by alessio on 16/03/19.
//

#ifndef ALL_ULTIMO_GAS_SINGLERACE_PAGE2_H
#define ALL_ULTIMO_GAS_SINGLERACE_PAGE2_H

#include "Menu_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"
#include "Race.h"

using namespace sf;
using namespace std;

class SingleRace_Page2 : public Menu_State {

public:

    SingleRace_Page2(RenderWindow &window, Error &error, int weath, int lap);

    ~SingleRace_Page2();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_singleraceon[10];
    Sprite S_singleraceon[10];
    int circuitrace, Type_race;
    int meteo, giri, chooseCar=3;
};


#endif //ALL_ULTIMO_GAS_SINGLERACE_PAGE2_H
