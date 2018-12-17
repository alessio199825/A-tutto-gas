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
    Championship champion;
    Single_Race singlerace;
    Time_Trial timetrial;
    Setting setting;
    Error error;
    Race race;
    Car car;
    Weather weath;
    Texture T_championship[10], T_singlerace[16], T_timetrial[10], T_setting[8], T_singleraceon[10], T_Error[2], T_loadMachine[3], T_rain[3];
    Sprite S_rain[3], S_championship[10], S_singlerace[16], S_timetrial[10], S_setting[8], S_singleraceon[10], S_Error[2], S_loadMachine[3];
    Clock C_show;
    Texture T_tilemaps, T_Instruction[6], T_MachinePlayer, T_Pause[2], T_Flag;
    Sprite S_tilemaps, S_Instruction[6], S_MachinePlayer, S_Pause[2], S_Flag;
    int Lap=0, meteo=0, time_circuit=0, singleraceon=0, circuiton=0, championship_car=0;
    int menu_state = 0;
    int Setting_control=0, control_timeTrial=0;
    int x_load=20, load_degree=0;
    double posx=0, posy=0, x_position=0, y_position=150, degree_CarPlayer=0, degreeConst=0;
    float CarPlayer_Acc=0.5, y_CarPlayer, x_CarPlayer;



    void createMenu();
    int setMenuState();
    int getChampionship();
    int getSetting();
    int getSingle_Race();
    int getTime_Trial();
    double getMousePosx();
    double getMousePosy();
    bool load_Machine();


protected:

    int control_time=0;
    int Control_show=0;
    bool music_loadloop=false, music_menuloop=false, control_setRace=true;
    Texture T_load[2];
    Sprite S_load[2];
    Texture T_menu[7];
    Sprite S_menu[7];
    Music music_load, music_menu;
    bool window_error_setCha=false;
    bool window_error_setRace=false;
    bool window_error_Single=false;
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

};

#endif