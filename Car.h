//
// Created by alessio on 06/12/18.
//

#ifndef ALL_ULTIMO_GAS_CAR_H
#define ALL_ULTIMO_GAS_CAR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Control.h"
#include "Error.h"
#include "Collision.h"
#include <string>

using namespace std;
using namespace sf;

class Car{

public:

    Car();

    Control control;

    Car(Collision &carcollision);

    void setMachinePlayer(RenderWindow &window, int num_circuit, Error &error, int Type_race, int chooseCar);
    void Car_Player_Movement(RenderWindow &window, Error &error, int circuitrace);
    float getY_CarPlayer() const;
    float getX_CarPlayer() const;
    bool End_Race(int giri, int &position, int circuitrace);

    int getPos() const;

    float y_CarPlayer, x_CarPlayer;


private:

    Collision *Carcollision;
    int start, Reverse, lap=0, intermediate=0, pos;
    float CarPlayer_Acc=2, const_Acc=0.1, const_Brake=0.05;
    double degreeConst, degree_CarPlayer;
    bool done=false, controlCollision=false, controlCollision1=false;
    Sprite S_MachinePlayer, S_Box1, S_Box2;
    Texture T_MachinePlayer, T_Box1, T_Box2;
    Clock clockCollision, clockCollision1;
    Time timeCollision, timeCollision1;
    void Accelerate();
    void Accelerate_Out();
    void Do_Reverse();
    void Do_Reverse_Out();
    void Turn_Right();
    void Turn_Left();


};

#endif //ALL_ULTIMO_GAS_CAR_H

