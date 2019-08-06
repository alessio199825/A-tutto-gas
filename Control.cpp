//
// Created by alessio on 01/12/18.
//

#include "Control.h"
#include "Load_Exception.h"

Control::Control() = default;

int Control::SetControl(RenderWindow &window, Error &error, int num_circuit, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    switch (num_circuit) {

        case 1:
            return CircuitOne(window, error, y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        case 3:
            return CircuitThree(window, error, y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        case 2:
            return CircuitTwo(window, error, y_CarPlayer, x_CarPlayer, degree_CarPlayer);

        default: break;
    }

    return -1;
}

int Control::CircuitOne(RenderWindow &window, Error &error, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));

    try {
        if (image1 == 0) {
            if(!circuit_one.loadFromFile("Control/control1.bmp"))
                throw Load_exception("Load_exception:Impossibile caricare file");
            image1 = 1;
        }
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
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

int Control::CircuitTwo(RenderWindow &window, Error &error, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * cos((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));

    try {
        if (image2 == 0) {
            if (!circuit_two.loadFromFile("Control/control2.bmp"))
                throw Load_exception("Load_exception:Impossibile caricare file");
            image2 = 1;
        }
    }
    catch(Load_exception e) {
        window.close();
        error.Check_Image(window);
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

int Control::CircuitThree(RenderWindow &window, Error &error, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * sin((degree_CarPlayer * M_PI) / 180));

    try {
        if (image3 == 0) {
            if (!circuit_three.loadFromFile("Control/control3.bmp"))
                throw Load_exception("Load_exception:Impossibile caricare file");
            image3 = 1;
        }
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
    }

    green=circuit_three.getPixel(807,422);
    black=circuit_three.getPixel(5,5);
    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }

    if(color == green){
        return 1;
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
        default: break;
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

    color=circuit_three.getPixel(static_cast<unsigned int>(x_CarPlayer), static_cast<unsigned int>(y_CarPlayer));

    if(color == black){
        return 2;
    }

    if(color == green){
        return 1;
    }

    return 0;
}