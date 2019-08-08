//
// Created by alessio on 19/03/19.
//

#ifndef ALL_ULTIMO_GAS_LOAD_PAGE_H
#define ALL_ULTIMO_GAS_LOAD_PAGE_H

#include "Menu_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"
#include "Race_Page.h"

using namespace sf;
using namespace std;

class Load_Page : public Menu_State {

public:

    Load_Page(RenderWindow &window, Error &error, int circuitrace, int Type_race, int meteo, int giri, int chooseCar);

    ~Load_Page();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_planisphere[4];
    Sprite S_planisphere[4];
    bool start_Race=false, Option_Race;
    int degree_Tyre=0;
    float x_Tyre=20;
    int num_circuit, colore_macchina, Race_type, weath, lap;
};


#endif //ALL_ULTIMO_GAS_LOAD_PAGE_H
