//
// Created by alessio on 13/03/19.
//

#ifndef ALL_ULTIMO_GAS_MENU_STATE_H
#define ALL_ULTIMO_GAS_MENU_STATE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;

class Menu_State {

public:

    Menu_State();

    virtual ~Menu_State();

    virtual bool getState();
    virtual void setState(bool change);
    virtual void draw(RenderWindow &window)=0;
    virtual void setWindow(Error &error, RenderWindow &window) =0;
    virtual Menu_State *getNewPage(RenderWindow &window, Error &error) =0;
    virtual int getActivities(Event event, RenderWindow &window)=0;


protected:

    bool pageChanged;
    int pageIndex=-1;

private:



};



#endif //ALL_ULTIMO_GAS_MENU_STATE_H
