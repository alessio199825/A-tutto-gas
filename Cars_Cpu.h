//
// Created by alessio on 18/12/18.
//

#ifndef ALL_ULTIMO_GAS_CARS_CPU_H
#define ALL_ULTIMO_GAS_CARS_CPU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Error.h"

using namespace std;
using namespace sf;

class Cars_Cpu {

public:

    Cars_Cpu();

    void createMachine(RenderWindow &window, Error &error);
    void A_star(RenderWindow &window);

private:

    float x_cpu=160, y_cpu=342;
    Texture T_CpuCar[7];
    Sprite S_CpuCar[7];

};


#endif //ALL_ULTIMO_GAS_CARS_CPU_H
