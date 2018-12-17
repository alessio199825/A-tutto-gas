//
// Created by alessio on 01/12/18.
//

#ifndef PROJECT_CONTROL_H
#define PROJECT_CONTROL_H

#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class Control {
public:
    Control();
    int SetControl(int numcircuit, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);

protected:

    int image=0, image3=0, image2=0;
    Image CircuitOne, CircuitTwo, CircuitThree;
    Color Red, Black, color;
    int CircuitOne_control(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);
    int CircuitTwo_control(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);
    int CircuitThree_control(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);

};


#endif //PROJECT_CONTROL_H
