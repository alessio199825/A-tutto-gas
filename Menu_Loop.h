//
// Created by alessio on 19/03/19.
//

#ifndef ALL_ULTIMO_GAS_MENU_LOOP_H
#define ALL_ULTIMO_GAS_MENU_LOOP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"
#include "Championship_Page.h"
#include "SingleRace_Page.h"
#include "SingleRace_Page2.h"
#include "TimeTrial_Page.h"
#include "Setting_Page.h"
#include "State_Option.h"
#include "LoadMenu_Page.h"
#include "Race_Page.h"
#include "Song.h"


using namespace sf;
using namespace std;

class Menu_Loop {

public:

    Menu_Loop();

    ~Menu_Loop();

    void generateWindow(Error &error);

private:

    Song song;

    Event event;

    RenderWindow window;

    int pageIndex, control_time;

    int Index;


};


#endif //ALL_ULTIMO_GAS_MENU_LOOP_H
