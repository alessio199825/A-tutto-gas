//
// Created by alessio on 18/12/18.
//

#ifndef ALL_ULTIMO_GAS_CARS_CPU_H
#define ALL_ULTIMO_GAS_CARS_CPU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Cars_Cpu {

public:
    Cars_Cpu();

    bool createMachine(Texture *T_CpuCar, Sprite *S_CpuCar, float *x_cpu, float *y_cpu);
    void A_star(float *x_cpu, float *y_cpu, Sprite *S_CpuCar);
};


#endif //ALL_ULTIMO_GAS_CARS_CPU_H
