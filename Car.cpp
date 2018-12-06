//
// Created by alessio on 06/12/18.
//

#include "Car.h"

#include <iostream>
#include <math.h>

Car::Car() {
}

bool Car::setMachinePlayer(int num_circuit, Sprite *S_MachinePlayer, Texture *T_MachinePlayer, float *x_CarPlayer, float *y_CarPlayer, double *degree_CarPlayer, double *degreeConst) {
    if (!T_MachinePlayer->loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/race/macchina6.png")) {
        return true;
    }
    S_MachinePlayer->setTexture(*T_MachinePlayer);
    S_MachinePlayer->setOrigin(9.5, 0);
    switch(num_circuit) {
        case 1:
            *x_CarPlayer = 160;
            *y_CarPlayer = 312;
            *degreeConst = 180;
            break;
        case 2:
            *x_CarPlayer = 462;
            *y_CarPlayer = 14;
            *degreeConst = 270;
            break;
        case 3:
            *x_CarPlayer = 560;
            *y_CarPlayer = 550;
            *degreeConst = 90;
            break;
        default:
            break;
    }
    S_MachinePlayer->setPosition(Vector2f(*x_CarPlayer, *y_CarPlayer));
    S_MachinePlayer->setRotation(static_cast<float>(*degree_CarPlayer + *degreeConst));
    return false;
}
void Car::Car_Player(Sprite *S_MachinePlayer, float *CarPlayer_Acc, double *degree_CarPlayer, float *y_CarPlayer, float *x_CarPlayer, double *degreeConst, int num_circuit) {
    switch (control.SetControl(num_circuit, *y_CarPlayer, *x_CarPlayer, *degree_CarPlayer)) {
        case 0:
            Car_PlayerAcc(degreeConst, CarPlayer_Acc, y_CarPlayer, x_CarPlayer, degree_CarPlayer);
            Car_PlayerRet(degreeConst, degree_CarPlayer, y_CarPlayer, x_CarPlayer);
            Car_PlayerRi(degree_CarPlayer);
            Car_PlayerLe(degree_CarPlayer);
            break;
        case 1:
            Car_PlayerAcc_Out(degreeConst, CarPlayer_Acc, y_CarPlayer, x_CarPlayer, degree_CarPlayer);
            Car_PlayerRet_Out(degreeConst, degree_CarPlayer, y_CarPlayer, x_CarPlayer);
            Car_PlayerRi(degree_CarPlayer);
            Car_PlayerLe(degree_CarPlayer);
            break;
        case 2:
            Car_PlayerRet(degreeConst, degree_CarPlayer, y_CarPlayer, x_CarPlayer);
            break;
        default: break;
    }
    S_MachinePlayer->setRotation(static_cast<float>(*degree_CarPlayer + *degreeConst));
    S_MachinePlayer->setPosition(Vector2f(*x_CarPlayer, *y_CarPlayer));
}
void Car::Car_PlayerRet(double *degreeConst, double *Degree_CarPlayer, float *y_CarPlayer, float *x_CarPlayer) {      //retromarcia
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        *x_CarPlayer = static_cast<float>(*x_CarPlayer - 0.5 * cos(((*Degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
        *y_CarPlayer = static_cast<float>(*y_CarPlayer - 0.5 * sin(((*Degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
    }
}
void Car::Car_PlayerAcc(double *degreeConst, float *CarPlayer_Acc, float *y_CarPlayer, float *x_CarPlayer, double *degree_CarPlayer) { //accelerazione seguendo con freno motore
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        start=1;
        if (*CarPlayer_Acc < 0.5) {
            *CarPlayer_Acc = *CarPlayer_Acc + const_Acc;
        }
        *x_CarPlayer = static_cast<float>(*x_CarPlayer + *CarPlayer_Acc * cos(((*degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
        *y_CarPlayer = static_cast<float>(*y_CarPlayer + *CarPlayer_Acc * sin(((*degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
    }
    else {
        if (0 < *CarPlayer_Acc && start == 1) {
            *CarPlayer_Acc = *CarPlayer_Acc - const_Brake;
            *x_CarPlayer = static_cast<float>(*x_CarPlayer + *CarPlayer_Acc * cos(((*degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
            *y_CarPlayer = static_cast<float>(*y_CarPlayer + *CarPlayer_Acc * sin(((*degree_CarPlayer + *degreeConst + 90)* M_PI) / 180));
        }
    }
}
void Car::Car_PlayerRi(double *degree_CarPlayer) {
    if (Keyboard::isKeyPressed(Keyboard::Right))     //incrementa l'angolo verso destra
        *degree_CarPlayer = *degree_CarPlayer + 0.7;
}
void Car::Car_PlayerLe(double *degree_CarPlayer) {
    if (Keyboard::isKeyPressed(Keyboard::Left))      //decrementa l'angolo verso sinistra
        *degree_CarPlayer = *degree_CarPlayer - 0.7;
}
void Car::Car_PlayerAcc_Out(double *degreeConst, float *CarPlayer_Acc, float *y_CarPlayer, float *x_CarPlayer, double *degree_CarPlayer) {
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        start=1;
        *CarPlayer_Acc = 0.1;
        *x_CarPlayer = static_cast<float>(*x_CarPlayer + *CarPlayer_Acc * cos(((*degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
        *y_CarPlayer = static_cast<float>(*y_CarPlayer + *CarPlayer_Acc * sin(((*degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
    }
    else {
        if (0 < *CarPlayer_Acc && start == 1) {
            *CarPlayer_Acc = *CarPlayer_Acc - const_Brake;
            *x_CarPlayer = static_cast<float>(*x_CarPlayer + *CarPlayer_Acc * cos(((*degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
            *y_CarPlayer = static_cast<float>(*y_CarPlayer + *CarPlayer_Acc * sin(((*degree_CarPlayer + *degreeConst + 90)* M_PI) / 180));
        }
    }
}
void Car::Car_PlayerRet_Out(double *degreeConst, double *Degree_CarPlayer, float *y_CarPlayer, float *x_CarPlayer) {
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        *x_CarPlayer = static_cast<float>(*x_CarPlayer - 0.1 * cos(((*Degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
        *y_CarPlayer = static_cast<float>(*y_CarPlayer - 0.1 * sin(((*Degree_CarPlayer + *degreeConst + 90) * M_PI) / 180));
    }
}
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
CarPlayer::CarPlayer() {
}
void CarBehavior::Accelerates() {
}
void CarBehavior::Restrains() {
}
void CarBehavior::Reverse_gear() {
}
void CarBehavior::GO_left() {
}
void CarBehavior::GO_right() {
}
SoundBehavior::SoundBehavior() {
}
void SoundBehavior::AlgorithmAcceleration() {
}
void SoundBehavior::AlgorithmBrake() {
}
void SoundBehavior::AlgorithmBase() {
}
void Basetrajectory::A_star() {
}
CarBehavior::CarBehavior() {
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
void CarsCPU::setCpuStrategy() {
}
void CarsCPU::getCpuStrategy() {
}
CarsCPU::CarsCPU() {
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
