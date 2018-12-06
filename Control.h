//
// Created by alessio on 01/12/18.
//

#ifndef PROJECT_CONTROL_H
#define PROJECT_CONTROL_H

#include <math.h>
#include <iostream>

using namespace std;


class Control {
public:
    Control();
    int SetControl(int numcircuit, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);

protected:

    int CircuitOne_control(float y_CarPlayer, float x_CarPlayer);
    int CircuitTwo_control(float y_CarPlayer, float x_CarPlayer);
    int CircuitThree_control(float y_CarPlayer, float x_CarPlayer);

};


#endif //PROJECT_CONTROL_H
