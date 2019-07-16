//
// Created by alessio on 16/03/19.
//

#ifndef ALL_ULTIMO_GAS_SINGLERACE_H
#define ALL_ULTIMO_GAS_SINGLERACE_H

#include "Menu_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;
using namespace std;


class SingleRace_Page : public Menu_State {

public:

    SingleRace_Page(RenderWindow &window, Error &error);

    ~SingleRace_Page();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_singlerace[15];
    Sprite S_singlerace[15];
    int lap;
    int weath;

};


#endif //ALL_ULTIMO_GAS_SINGLERACE_H
