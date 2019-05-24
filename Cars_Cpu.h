//
// Created by alessio on 18/12/18.
//

#ifndef ALL_ULTIMO_GAS_CARS_CPU_H
#define ALL_ULTIMO_GAS_CARS_CPU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Error.h"
#include <vector>

using namespace std;
using namespace sf;

class Cars_Cpu {

public:

    Cars_Cpu();

    void createMachine(RenderWindow &window, Error &error);
    void moveCar(int x_CpuCar, int y_CpuCar);
    float getX_cpu() const;
    float getY_cpu() const;

    void setX_cpu(float x_cpu);

    void setY_cpu(float y_cpu);

    void setCar(int x,int y);
    void drawCpu(RenderWindow &window);
    void setPos();
    const vector<Vector2f> &getPosCar() const;

private:

    float x_cpu=160, y_cpu=342;
    Texture T_CpuCar[7];
    Sprite S_CpuCar[7];
    vector<Vector2f> posCar;

    int index=0, i=0;


};


#endif //ALL_ULTIMO_GAS_CARS_CPU_H
