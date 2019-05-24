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
#include "Control_Cpu.h"
#include "A_Star.h"


using namespace sf;


class Race_Page : public Menu_State{

public:

    Race_Page(RenderWindow &window, Error &error, int num_circuit, int Race_type, bool weath);

    ~Race_Page();

    Weather weath;
    Cars_Cpu cars_cpu;
    Song song;
    Error error;
    Control_Cpu control_cpu;
    Car car;
    Race race;
    Traffic_Light traffic_light;
    Circuit circuit;
    A_Star a_star;
    MapSearchNode mapsearchnode;

    double getMousePosX(RenderWindow &window);

    double getMousePosY(RenderWindow &window);

    void draw(RenderWindow &window);

    int getActivities(Event event, RenderWindow &window);

    void setWindow(Error &error, RenderWindow &window);

    Menu_State *getNewPage(RenderWindow &window, Error &error);

    double posx, posy;

    int x_CpuCar, y_CpuCar;



private:

    int circuitrace, Type_race;
    bool control_setRace=true, meteo, flag=false;
    Texture T_Flag;
    Sprite S_Flag;
    Time timesCpu;
    Clock clockCpu;
};


#endif //ALL_ULTIMO_GAS_RACE_PAGE_H