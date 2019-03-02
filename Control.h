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
    int SetControlReverse(int numcircuit, float y_CarPlayer, float x_CarPlayer);

private:

    int image1=0, image2=0, image3=0;
    Image circuit_one, circuit_two, circuit_three;
    Color red, black, color;
    int CircuitOne(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);
    int CircuitTwo(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);
    int CircuitThree(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer);
    int CircuitOneReverse(float y_CarPlayer, float x_CarPlayer);
    int CircuitTwoReverse(float y_CarPlayer, float x_CarPlayer);
    int CircuitThreeReverse(float y_CarPlayer, float x_CarPlayer);

};


#endif //PROJECT_CONTROL_H
