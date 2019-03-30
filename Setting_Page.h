//
// Created by alessio on 19/03/19.
//

#ifndef ALL_ULTIMO_GAS_SETTING_PAGE_H
#define ALL_ULTIMO_GAS_SETTING_PAGE_H

#include "Menu_State.h"

class Setting_Page : public Menu_State{

public:

    Setting_Page(RenderWindow &window, Error &error);

    ~Setting_Page();

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

private:

    Texture T_setting[6];
    Sprite S_setting[6];

};


#endif //ALL_ULTIMO_GAS_SETTING_PAGE_H
