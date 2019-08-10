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

    bool createMachine(RenderWindow &window, Error &error);
    void moveCar();

    void setCar(int x,int y);
    void drawCpu(RenderWindow &window);
    void setPos();
    const vector<Vector2f> &getPosCar() const;

    void setCircuit(int circuit);

    int getPosition(int giri, int &position);

    const int getVector_position(int i);

    int carNumber, vector_position[5];

private:



    int x_cpu[5], y_cpu[5];
    int circuit;
    float degreeCPU[5];
    Texture T_CpuCar[5];
    Sprite S_CpuCar[5];
    vector<Vector2f> posCar;
    int dim_trajectory[5], dim_tmp[5], step[5];
    int index=0, i=0;
    int X_CPU[300][5];
    int Y_CPU[300][5];
    bool step2[5];
    int lap[5];
    int intermediate[5];

    Clock C_Step[7];
    Time time_Step[7];


};


#endif //ALL_ULTIMO_GAS_CARS_CPU_H
