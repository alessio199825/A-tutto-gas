//
// Created by alessio on 16/05/19.
//

#ifndef ALL_ULTIMO_GAS_CONTROL_CPU_H
#define ALL_ULTIMO_GAS_CONTROL_CPU_H

#include "Error.h"
#include "Cars_Cpu.h"

class Control_Cpu {

public:
    void LoadControlMap(RenderWindow &window, Error &error, int numcircuit);
    int GetCostNode(int x, int y);

private:
    bool map=false, example=false;
    Image ControlMap, ExampleColor;
    Color Rosso, Nero, Giallo, Colore;
};


#endif //ALL_ULTIMO_GAS_CONTROL_CPU_H
