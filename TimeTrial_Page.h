//
// Created by alessio on 19/03/19.
//

#ifndef ALL_ULTIMO_GAS_TIMETRIAL_PAGE_H
#define ALL_ULTIMO_GAS_TIMETRIAL_PAGE_H

#include "Menu_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;
using namespace std;

class TimeTrial_Page : public Menu_State {

public:

    TimeTrial_Page(RenderWindow &window, Error &error);

    ~TimeTrial_Page();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_timetrial[10];
    Sprite S_timetrial[10];
    int circuitrace, Type_race, chooseCar=3;
    bool meteo, giri=0;

};


#endif //ALL_ULTIMO_GAS_TIMETRIAL_PAGE_H
