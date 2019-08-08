//
// Created by alessio on 20/03/19.
//

#ifndef ALL_ULTIMO_GAS_RACE_PAGE_H
#define ALL_ULTIMO_GAS_RACE_PAGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu_State.h"
#include "Error.h"
#include "Car.h"
#include "Traffic_Light.h"
#include "Race.h"
#include "Circuit.h"
#include "Song.h"
#include "Cars_Cpu.h"
#include "Weather.h"
#include <fstream>
#include <iostream>


using namespace sf;
using namespace std;


class Race_Page : public Menu_State{

public:

    Race_Page(RenderWindow &window, Error &error, int num_circuit, int Race_type, int weath, int lap, int colore_macchina);

    ~Race_Page();

    Race_Page();

    Weather weath;
    Cars_Cpu cars_cpu;
    Song song;
    Error error;
    Car car;
    Race race;
    Traffic_Light traffic_light;
    Circuit circuit;

    double getMousePosX(RenderWindow &window);

    double getMousePosY(RenderWindow &window);

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

    double posx, posy;

    int x_CpuCar=162, y_CpuCar=368, chooseCar;



private:

    void SaveCircuit();

    int Type_race;
    int circuitrace;
    bool control_setRace=true, assignament=true;
    int meteo, giri;
    bool flag1=false, flag=false;

    //int *X_CPU = new int [dim_trajectory];
    //int *Y_CPU = new int [dim_trajectory];


};


#endif //ALL_ULTIMO_GAS_RACE_PAGE_H
