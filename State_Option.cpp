//
// Created by alessio on 19/03/19.
//

#include "State_Option.h"

State_Option::State_Option() = default;

State_Option::~State_Option() = default;

State_Option::State_Option(Menu_State *gContext) {

    menu_State=gContext;
}

void State_Option::changeState(RenderWindow &window, Error &error) {
    if (menu_State){

        Menu_State* gContext = menu_State->getNewPage(window, error);

        delete menu_State;

        menu_State = gContext;
    }

}

void State_Option::setWindow(Error &error, RenderWindow &window) {

    menu_State->setWindow(error, window);

}

void State_Option::draw(RenderWindow &window) {

    menu_State -> draw(window);

}

int State_Option::getActivities(Event event, RenderWindow &window) {

    menu_State -> getActivities(event, window);

}

bool State_Option::getState() {
    return menu_State -> getState();
}

