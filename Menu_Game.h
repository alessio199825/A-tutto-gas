//
// Created by alessio on 13/03/19.
//

#ifndef ALL_ULTIMO_GAS_MENU_GAME_H
#define ALL_ULTIMO_GAS_MENU_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu_State.h"
#include "Error.h"

using namespace sf;

class Menu_Game: public Menu_State{

public:

    Menu_Game(RenderWindow &window, Error &error);

    ~Menu_Game();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_menu[6];
    Sprite S_menu[6];

};


#endif //ALL_ULTIMO_GAS_MENU_GAME_H
