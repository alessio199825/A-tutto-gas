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
        circuit_one.loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Control/control.bmp");
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
        circuit_two.loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Control/control2.bmp");
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
        circuit_three.loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Control/control3.bmp");
        image3=1;
    }
    black=circuit_three.getPixel(5,5);
    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }
    return 0;
}


