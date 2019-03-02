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
#include <iostream>


using namespace std;
using namespace sf;

class Menu {

public:

    Menu();

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

    double posx=0, posy=0;
    int circuiton=0;
    int time_circuit=0;
    int Setting_control=0;
    int load_degree=0, meteo=1;
    bool control_C;

    void createMenu();
    int setMenuState();
    int getChampionship();
    int getSetting();
    int getSingle_Race();
    double getMousePosx();
    double getMousePosy();
    int getTime_Trial();
    bool load_Machine();

protected:

    int control_time=0, singleraceon=0, menu_state = 0, control_timeTrial=0, championship_car=0, Lap=0, x_load=20;
    bool control_setRace=true;

    int Control_show=0;
    bool window_error_timetrial=false;
    bool window_error_setting=false;
    bool window_error_instruction=false;
    bool window_error_singlerace=false;
    bool window_error_tilemaps=false;
    bool window_error_tilemaps1=false;
    bool window_error_Timetrial=false;
    bool Error_Font_Setting=false;
    bool load_machine_error=false, load_machine_error1=false;
    int degree_load=0;

private:

    bool music_menuloop=false, music_loadloop=false;
    Music music_load;
    Music music_menu;
    Sprite S_load[2], S_menu[7],S_loadMachine[3];
    Texture T_load[2], T_menu[7],T_loadMachine[3];

};

#endif