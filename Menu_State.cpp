//
// Created by alessio on 13/03/19.
//

#include "Menu_State.h"

Menu_State::Menu_State() {

    pageChanged=false;
}

bool Menu_State::getState() {

    return pageChanged;
}

void Menu_State::setState(bool change) {

    pageChanged=change;
}

Menu_State::~Menu_State() = default;


