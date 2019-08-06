//
// Created by alessio on 18/12/18.
//

#ifndef ALL_ULTIMO_GAS_CARS_CPU_H
#define ALL_ULTIMO_GAS_CARS_CPU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Error.h"
#include "A_Star.h"
#include <vector>

using namespace std;
using namespace sf;

class Cars_Cpu {

public:

    Cars_Cpu();

    Cars_Cpu(int x, int y) { x_cpu[0]=x; y_cpu[0]=y;}

    A_Star a_star;

    void createMachine(RenderWindow &window, Error &error);
    void moveCar();

    void setCar(int x,int y);
    void drawCpu(RenderWindow &window);
    void setPos();
    const vector<Vector2f> &getPosCar() const;

    void setCircuit(int circuit);

private:



    int x_cpu[7], y_cpu[7];
    int circuit;
    float degreeCPU[7];
    Texture T_CpuCar[7];
    Sprite S_CpuCar[7];
    vector<Vector2f> posCar;
    int dim_trajectory[7], dim_tmp[7], step[7];
    int index=0, i=0;
    int X_CPU[200];
    int Y_CPU[200];
    bool step2[7];

    Clock C_Step;
    Time time_Step;


};


#endif //ALL_ULTIMO_GAS_CARS_CPU_H
