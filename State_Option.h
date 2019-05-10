//
// Created by alessio on 19/03/19.
//

#ifndef ALL_ULTIMO_GAS_STATE_OPTION_H
#define ALL_ULTIMO_GAS_STATE_OPTION_H

#include "Menu_State.h"

using namespace std;

class State_Option {

public:

    State_Option();

    State_Option(Menu_State *gContext);

    virtual ~State_Option();

    bool getState();

    void changeState(RenderWindow &window, Error &error);

    void draw(RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);



private:

    Menu_State* menu_State;

};


#endif //ALL_ULTIMO_GAS_STATE_OPTION_H
