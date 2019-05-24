
// Created by alessio on 06/12/18.
//

#include "Car.h"

#include <iostream>
#include <math.h>

Car::Car() {
}

void Car::setMachinePlayer(RenderWindow &window, int circuitrace, Error &error, int Type_race) {

    try {
        if (!T_MachinePlayer.loadFromFile("race/macchina6.png")) {
            throw "impossibile caricare Texture";
        }
    }
    catch(...){
        error.Check_Image(window);
    }

    S_MachinePlayer.setTexture(T_MachinePlayer);
    S_MachinePlayer.setOrigin(9.5, 0);
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
                    y_CarPlayer = 44;
                    degreeConst = 270;
                    break;
                case 3:
                    x_CarPlayer = 525;
                    y_CarPlayer = 513;
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
    window.draw(S_MachinePlayer);
}

void Car::Car_Player_Movement(RenderWindow &window, Error &error, int circuitrace) {
    switch (control.SetControl(window, error, circuitrace, y_CarPlayer, x_CarPlayer, degree_CarPlayer)) {

        case 0:
            Accelerate();
            Turn_Right();
            Turn_Left();
            Reverse=0;
            break;
        case 1:
            Accelerate_Out();
            Turn_Right();
            Turn_Left();
            Reverse=1;
            break;
        case 2:
            Do_Reverse();
            Reverse=2;
            break;
        default: break;
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
    S_MachinePlayer.setRotation(static_cast<float>(degree_CarPlayer + degreeConst));
    S_MachinePlayer.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    window.draw(S_MachinePlayer);

}
void Car::Do_Reverse() {      //retromarcia
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        CarPlayer_Acc=0;
        x_CarPlayer = static_cast<float>(x_CarPlayer - 0.5 * cos((degree_CarPlayer + degreeConst + 90) * M_PI / 180));
        y_CarPlayer = static_cast<float>(y_CarPlayer - 0.5 * sin((degree_CarPlayer + degreeConst + 90) * M_PI / 180));
        }

    }

void Car::Accelerate() { //accelerazione seguendo con freno motore
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        start=1;
        if (CarPlayer_Acc < 0.5) {
            CarPlayer_Acc = CarPlayer_Acc + const_Acc;
        }
        x_CarPlayer = static_cast<float>(x_CarPlayer + CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
        y_CarPlayer= static_cast<float>(y_CarPlayer + CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));

    }
    else {
        if (0 < CarPlayer_Acc && start==1) {
            CarPlayer_Acc = CarPlayer_Acc - const_Brake;
            x_CarPlayer = static_cast<float>(x_CarPlayer + CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
            y_CarPlayer = static_cast<float>(y_CarPlayer + CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90)* M_PI) / 180));
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


/*
void CarPlayer::setSoundBehavior() {
}
void CarPlayer::getSuoundBehavior() {
}
bool CarPlayer::getCarBehavior() {
    return false;
}
void CarPlayer::setUpgrade() {
}
void CarPlayer::setCarBehavior() {
}
void CarPlayer::getUpgrade() {
}
void CarPlayer::setBasetrajectory() {
}
bool CarPlayer::getBasetrajectory() {
    return false;
}
*/

/*SoundBehavior::SoundBehavior() {
}
void SoundBehavior::AlgorithmAcceleration() {
}
void SoundBehavior::AlgorithmBrake() {
}
void SoundBehavior::AlgorithmBase() {
}*/
/*
void Basetrajectory::MapSearchNode() {
}

int Motore::Upgrade_Displacement() {
    return 0;
}
Motore::Motore() {
}
int Telaio::Upgrade_Weight() {
    return 0;
}
Telaio::Telaio() {
}
string Carrozzeria::Upgrade_Aerodynamics() {
    return std::__cxx11::string();
}
Carrozzeria::Carrozzeria() {
}

void SafetyCar::setCpuStrategy() {
}
void SafetyCar::getCpuStrategy() {
}
SafetyCar::SafetyCar() {
}
void CpuStrategy::MapSearchNode() {
}
int CpuStrategy::do_trajectory() {
    return 0;
}
bool CpuStrategy::get_SafetyCar() {
    return false;
}
CpuStrategy::CpuStrategy() {
}
void Trajectory::A_star1() {
}
Trajectory::Trajectory() {
}
void Trajectory_safetycar::A_star2() {
}
Trajectory_safetycar::Trajectory_safetycar() {
}
void GeneralTrajectory::A_star3() {
}
GeneralTrajectory::GeneralTrajectory() {
}
*/
