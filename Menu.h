#ifndef PROGETTO_MENU_H
#define PROGETTO_MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Championship.h"
#include "Single_Race.h"
#include "Time_Trial.h"
#include "Setting.h"
#include "Error.h"
#include "Circuit.h"
#include "Race.h"
#include "Weather.h"
#include "Song.h"
#include "Traffic_Light.h"
#include <iostream>

using namespace std;
using namespace sf;

class Menu {

public:

    Menu();

    void GoRace();

    RenderWindow window;
    Event event;
    Single_Race singlerace;
    Time_Trial timetrial;
    Setting setting;
    Error error;
    Race race;
    Circuit circuit;
    Car car;
    Cars_Cpu cars_cpu;
    Weather weath;
    Traffic_Light traffic_light;
    Song song;

    double posx=0, posy=0;
    int time_circuit=0, circuiton=0;

private:

    int control_time=0, control_timeTrial=0, Lap=0/*servira*/, Setting_control=0;
    int load_degree=0, singleraceon=0, menu_state = 0, championship_car=0/*servira*/, degree_load=0, x_load=20, meteo=1;

    bool control_setRace=true;

    Sprite S_load[2], S_menu[7],S_loadMachine[3];
    Texture T_load[2], T_menu[7],T_loadMachine[3];

    void createMenu();
    int setMenuState();
    int getChampionship();
    int getSetting();
    int getSingle_Race();
    double getMousePosx();
    double getMousePosy();
    int getTime_Trial();
    void load_Machine();
};

#endif