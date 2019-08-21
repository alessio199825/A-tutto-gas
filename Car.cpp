
// Created by alessio on 06/12/18.
//

#include "Car.h"
#include "Load_Exception.h"
#include "Collision.h"

#include <iostream>
#include <math.h>

Car::Car() = default;

Car::Car(Collision &collision)  {

    Carcollision=&collision;
}

void Car::setMachinePlayer(RenderWindow &window, int circuitrace, Error &error, int Type_race, int chooseCar) {

    try {
        switch (chooseCar) {
            case 1:
            if (!T_MachinePlayer.loadFromFile("race/macchina1.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }
            break;
            case 2:
            if (!T_MachinePlayer.loadFromFile("race/macchina6.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }
            break;
            default:
            if (!T_MachinePlayer.loadFromFile("race/macchina2.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }
            break;
        }

        if (!Carcollision->CreateTextureAndBitmask(T_Box1, "Control/neroT.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }

        if (!Carcollision->CreateTextureAndBitmask(T_Box2, "Control/bianco.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
    }
    catch(Load_exception e){
        error.Check_Image(window);
    }

    if(Type_race==1)
        Type_race=2;

    S_MachinePlayer.setTexture(T_MachinePlayer);
    S_MachinePlayer.setOrigin(9.5, 0);

    S_Box1.setTexture(T_Box1);
    S_Box1.setOrigin(36, 8.5);

    S_Box2.setTexture(T_Box2);
    S_Box2.setOrigin(36, 8.5);

    degree_CarPlayer=0;

    switch(Type_race) {
        case 2:
            switch (circuitrace) {
                case 1:
                    x_CarPlayer = 160;
                    y_CarPlayer = 312;
                    degreeConst = 180;
                    break;
                case 2:
                    x_CarPlayer = 462;
                    y_CarPlayer = 36;
                    degreeConst = 270;
                    break;
                case 3:
                    x_CarPlayer = 532;
                    y_CarPlayer = 512;
                    degreeConst = 90;
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch (circuitrace) {
                case 1:
                    x_CarPlayer = 105;
                    y_CarPlayer = 302;
                    degreeConst = 180;
                    break;
                case 2:
                    x_CarPlayer = 620;
                    y_CarPlayer = 10;
                    degreeConst = 270;
                    break;
                case 3:
                    x_CarPlayer = 810;
                    y_CarPlayer = 440;
                    degreeConst = 60;
                    break;
                default:
                    break;
            }
        default:break;
    }

    S_MachinePlayer.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    S_MachinePlayer.setRotation(static_cast<float>(degree_CarPlayer + degreeConst));

    S_Box1.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    S_Box1.setRotation(static_cast<float>(degree_CarPlayer + degreeConst -90));

    S_Box2.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    S_Box2.setRotation(static_cast<float>(degree_CarPlayer + degreeConst -90));

    window.draw(S_MachinePlayer);
}

void Car::Car_Player_Movement(RenderWindow &window, Error &error, int circuitrace) {

    Carcollision->setSCar(S_Box1, S_Box2);

    if(Carcollision->CarPlayer_Menagement()){
        controlCollision=true;
        clockCollision.restart();
    }

    if(!controlCollision) {

        switch (control.SetControl(window, error, circuitrace, y_CarPlayer, x_CarPlayer, degree_CarPlayer)) {
            case 0:
                Accelerate();
                Turn_Right();
                Turn_Left();
                Reverse = 0;
                break;
            case 1:
                Accelerate_Out();
                Turn_Right();
                Turn_Left();
                Reverse = 1;
                break;
            case 2:
                Do_Reverse();
                Reverse = 2;
                break;
            default:
                break;
        }
    }else{

        CarPlayer_Acc=0;
    }

    if (Reverse == 0 || Reverse == 1)
    switch (control.SetControlReverse(circuitrace, y_CarPlayer, x_CarPlayer)){
        case 0:
            Do_Reverse();
            break;
        case 1:
            Accelerate_Out();
            Do_Reverse_Out();
            break;
        case 2:
            Accelerate();
            break;
        default:break;
    }

    timeCollision = clockCollision.getElapsedTime();

    if(timeCollision.asSeconds()>0.3){
        controlCollision=false;
    }

    S_MachinePlayer.setRotation(static_cast<float>(degree_CarPlayer + degreeConst));
    S_MachinePlayer.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    window.draw(S_MachinePlayer);

    S_Box1.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    S_Box1.setRotation(static_cast<float>(degree_CarPlayer + degreeConst -90));

    S_Box2.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    S_Box2.setRotation(static_cast<float>(degree_CarPlayer + degreeConst -90));

}
void Car::Do_Reverse() {      //retromarcia

    if (Keyboard::isKeyPressed(Keyboard::Down)) {

        if (Carcollision->CarPlayer_Reverse()) {
            controlCollision1 = true;
            clockCollision1.restart();
        }

        if (!controlCollision1) {
            CarPlayer_Acc = 0;
            x_CarPlayer = static_cast<float>(x_CarPlayer -
                                             0.5 * cos((degree_CarPlayer + degreeConst + 90) * M_PI / 180));
            y_CarPlayer = static_cast<float>(y_CarPlayer -
                                             0.5 * sin((degree_CarPlayer + degreeConst + 90) * M_PI / 180));
        }else {

            CarPlayer_Acc = 0;
        }

        timeCollision1 = clockCollision1.getElapsedTime();

        if (timeCollision1.asSeconds() > 0.3) {
            controlCollision1 = false;
        }
    }
}

void Car::Accelerate() { //accelerazione seguendo con freno motore
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        start=1;
        if (CarPlayer_Acc < 2) {
            CarPlayer_Acc = CarPlayer_Acc + const_Acc;
        }
        x_CarPlayer = static_cast<float>(x_CarPlayer + CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
        y_CarPlayer= static_cast<float>(y_CarPlayer + CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));

    }
    else {
        if (0 < CarPlayer_Acc && start == 1) {
            CarPlayer_Acc = CarPlayer_Acc - const_Brake;
            x_CarPlayer = static_cast<float>(x_CarPlayer +
                                             CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
            y_CarPlayer = static_cast<float>(y_CarPlayer +
                                             CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
        }
    }
}

void Car::Turn_Right() {
    if (Keyboard::isKeyPressed(Keyboard::Right))     //incrementa l'angolo verso destra
        degree_CarPlayer = degree_CarPlayer + 1;
}

void Car::Turn_Left() {
    if (Keyboard::isKeyPressed(Keyboard::Left))      //decrementa l'angolo verso sinistra
        degree_CarPlayer = degree_CarPlayer - 1;
}

void Car::Accelerate_Out() {
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        start=1;
        CarPlayer_Acc = 0.05;
        x_CarPlayer = static_cast<float>(x_CarPlayer + CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
        y_CarPlayer = static_cast<float>(y_CarPlayer + CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
    }
    else {
        if (0 < CarPlayer_Acc && start == 1) {
            CarPlayer_Acc = CarPlayer_Acc - const_Brake;
            x_CarPlayer = static_cast<float>(x_CarPlayer + CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
            y_CarPlayer = static_cast<float>(y_CarPlayer + CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90)* M_PI) / 180));
        }
    }
}
void Car::Do_Reverse_Out() {
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        x_CarPlayer = static_cast<float>(x_CarPlayer - 0.1 * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
        y_CarPlayer = static_cast<float>(y_CarPlayer - 0.1 * sin(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
    }
}

float Car::getY_CarPlayer() const {
    return y_CarPlayer;
}

float Car::getX_CarPlayer() const {
    return x_CarPlayer;
}

bool Car::End_Race(int giri, int &position, int circuitrace) {
    if(giri != 3 && giri != 5 && giri != 10){
        giri = 3;
    }
switch(circuitrace) {
    case 1:
        if (done) {
            return true;
        }
        if (y_CarPlayer >= 410 && x_CarPlayer >= 465 && y_CarPlayer <= 490 && x_CarPlayer <= 470) {
            intermediate = intermediate + 1;
            if (intermediate > lap) {
                intermediate = lap;
            }
        }

        if (y_CarPlayer >= 255 && y_CarPlayer <= 269 && x_CarPlayer >= 143 && x_CarPlayer <= 236 &&
            lap == intermediate) {
            lap++;
            if (lap == giri + 1) {
                done = true;
                pos = position;
                position++;
                return true;
            }
        }

        return false;
    case 2:
        if (done) {
            return true;
        }

        if (y_CarPlayer >= 478 && x_CarPlayer >= 495 && y_CarPlayer <= 543 && x_CarPlayer <= 510) {
            intermediate = intermediate + 1;
            if (intermediate > lap) {
                intermediate = lap;
            }
        }

        if (y_CarPlayer >= 23 && y_CarPlayer <= 90 && x_CarPlayer >= 520 && x_CarPlayer <= 535 &&
            lap == intermediate) {
            lap++;
            if (lap == giri + 1) {
                done = true;
                pos = position;
                position++;
                return true;
            }
        }

        return false;
    case 3:
        if (done) {
            return true;
        }

            if (y_CarPlayer >= 180 && x_CarPlayer >= 520 && y_CarPlayer <= 268 && x_CarPlayer <= 540) {
            intermediate = intermediate + 1;
            if (intermediate > lap) {
                intermediate = lap;
            }
        }

        if (y_CarPlayer >= 484 && y_CarPlayer <= 586 && x_CarPlayer >= 455 && x_CarPlayer <= 470 &&
            lap == intermediate) {
            lap++;
            if (lap == giri + 1) {
                done = true;
                pos = position;
                position++;
                return true;
            }
        }

        return false;
    default: break;
    }

    return false;
}

int Car::getPos() const {
    return pos;
}



