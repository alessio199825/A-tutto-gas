
// Created by alessio on 06/12/18.
//

#include "Car.h"

#include <iostream>
#include <math.h>

Car::Car() {
}

bool Car::setMachinePlayer(RenderWindow &window, int num_circuit) {
    if (!T_MachinePlayer.loadFromFile("race/macchina6.png")) {
        return true;
    }

    S_MachinePlayer.setTexture(T_MachinePlayer);
    S_MachinePlayer.setOrigin(9.5, 0);
    degree_CarPlayer=0;
    switch(num_circuit) {
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

    S_MachinePlayer.setPosition(Vector2f(x_CarPlayer, y_CarPlayer));
    S_MachinePlayer.setRotation(static_cast<float>(degree_CarPlayer + degreeConst));
    window.draw(S_MachinePlayer);
    return false;
}
void Car::Car_Player_Movement(RenderWindow &window, int num_circuit) {

    switch (control.SetControl(num_circuit, y_CarPlayer, x_CarPlayer, degree_CarPlayer)) {

        case 0:
            Accelerate();
            Turn_Right();
            Turn_Left();
            break;
        case 1:
            Accelerate_Out();
            Turn_Right();
            Turn_Left();
            break;
        case 2:
            Do_Reverse();
            break;
        default: break;
    }

    switch (control.SetControlReverse(num_circuit, y_CarPlayer, x_CarPlayer)){
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
        x_CarPlayer = static_cast<float>(x_CarPlayer - 0.5 * cos((degree_CarPlayer + degreeConst + 90) * M_PI / 180));
        y_CarPlayer = static_cast<float>(y_CarPlayer - 0.5 * sin((degree_CarPlayer + degreeConst + 90) * M_PI / 180));
       /* x_tmp = static_cast<float>(*x_CarPlayer - 0.5 * cos(((*Degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
        y_tmp = static_cast<float>(*y_CarPlayer - 0.5 * sin(((*Degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
        switch(control.SetControl(num_circuit, x_tmp, y_tmp, *Degree_CarPlayer)){
            case 0:
                *x_CarPlayer=x_tmp;
                *y_CarPlayer=y_tmp;
                break;
            case 1:
                Car_PlayerRet_Out(degreeConst, Degree_CarPlayer, y_CarPlayer, x_CarPlayer);
            break;
            default: break;*/

        }

    }

void Car::Accelerate() { //accelerazione seguendo con freno motore
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        start=1;
        if (CarPlayer_Acc < 1) {
            CarPlayer_Acc = CarPlayer_Acc + const_Acc;
        }
        x_CarPlayer = static_cast<float>(x_CarPlayer + CarPlayer_Acc * cos(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));
        y_CarPlayer= static_cast<float>(y_CarPlayer + CarPlayer_Acc * sin(((degree_CarPlayer + degreeConst + 90) * M_PI) / 180));

        /*cout << control.SetControl(num_circuit, static_cast<float>(x_tmp), static_cast<float>(y_tmp), *degree_CarPlayer) << endl;
        switch (control.SetControl(num_circuit, static_cast<float>(x_tmp), static_cast<float>(y_tmp),
                                   *degree_CarPlayer)) {
            case 0:
                *x_CarPlayer = x_tmp;
                *y_CarPlayer = y_tmp;

                break;
            case 1:
                Car_PlayerAcc_Out(degreeConst, CarPlayer_Acc, y_CarPlayer, x_CarPlayer, degree_CarPlayer);
                break;
            default:
                break;
        }*/
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
        CarPlayer_Acc = 0.1;
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
void Basetrajectory::A_star() {
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
void CpuStrategy::A_star() {
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
