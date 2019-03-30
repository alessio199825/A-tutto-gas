//
// Created by alessio on 19/03/19.
//

#ifndef ALL_ULTIMO_GAS_LOADMENU_PAGE_H
#define ALL_ULTIMO_GAS_LOADMENU_PAGE_H

#include <SFML/Graphics.hpp>
#include "Menu_State.h"
#include "Error.h"
#include "Song.h"

using namespace sf;

class LoadMenu_Page : public Menu_State {

public:

    LoadMenu_Page(RenderWindow &window, Error &error);

    ~LoadMenu_Page();

    Song song;

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    double degree_load=0;
    Clock C_load;
    Time time_load;
    Texture T_load[2];
    Sprite  S_load[2];

};


#endif //ALL_ULTIMO_GAS_LOADMENU_PAGE_H
