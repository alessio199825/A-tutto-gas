//
// Created by alessio on 08/08/19.
//

#ifndef ALL_ULTIMO_GAS_FLAG_PAGE_H
#define ALL_ULTIMO_GAS_FLAG_PAGE_H

#include "Menu_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"
#include "Song.h"

using namespace sf;
using namespace std;

class Flag_Page : public Menu_State {

public:

     Flag_Page(RenderWindow &window, Error &error, int Type_race);

    ~Flag_Page();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_Flag[10];
    Sprite S_Flag[10];

    int Race_type;

};


#endif //ALL_ULTIMO_GAS_FLAG_PAGE_H
