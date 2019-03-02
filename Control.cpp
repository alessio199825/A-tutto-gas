//
// Created by alessio on 01/12/18.
//

#include "Control.h"

Control::Control() {

}

int Control::SetControl(int num_circuit, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    switch (num_circuit) {

        case 1:
            return CircuitOne(y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        case 3:
            return CircuitThree(y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        case 2:
            return CircuitTwo(y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        default:
            return 0;

    }
}

int Control::CircuitOne(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));

    if(image1==0){
        circuit_one.loadFromFile("Control/control.bmp");
        image1=1;
    }
    red=circuit_one.getPixel(100,230);
    black=circuit_one.getPixel(290,220);
    color=circuit_one.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color== red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;

}

int Control::CircuitTwo(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * cos((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));

    if(image2==0){
        circuit_two.loadFromFile("Control/control2.bmp");
        image2=1;
    }
    red=circuit_two.getPixel(947,51);
    black=circuit_two.getPixel(1,1);
    color=circuit_two.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;
}

int Control::CircuitThree(float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * sin((degree_CarPlayer * M_PI) / 180));

    if(image3==0){
        circuit_three.loadFromFile("Control/control3.bmp");
        image3=1;
    }
    black=circuit_three.getPixel(5,5);
    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }
    return 0;
}

int Control::SetControlReverse(int numcircuit, float y_CarPlayer, float x_CarPlayer) {

    switch(numcircuit) {

        case 1:
            return CircuitOneReverse(y_CarPlayer, x_CarPlayer);

        case 2:
            return CircuitTwoReverse(y_CarPlayer, x_CarPlayer);

        case 3:
            return CircuitThreeReverse(y_CarPlayer, x_CarPlayer);
        default:return 0;
    }

}

int Control::CircuitOneReverse(float y_CarPlayer, float x_CarPlayer) {

    red=circuit_one.getPixel(100,230);
    black=circuit_one.getPixel(290,220);
    color=circuit_one.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color== red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;
}

int Control::CircuitTwoReverse(float y_CarPlayer, float x_CarPlayer) {

    red=circuit_two.getPixel(947,51);
    black=circuit_two.getPixel(1,1);
    color=circuit_two.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == red){
        return 1;
    }
    if(color == black){
        return 2;
    }
    return 0;
}

int Control::CircuitThreeReverse(float y_CarPlayer, float x_CarPlayer) {

    black=circuit_three.getPixel(5,5);
    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }
    return 0;
}


