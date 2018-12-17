//
// Created by alessio on 06/12/18.
//

#ifndef ALL_ULTIMO_GAS_CAR_H
#define ALL_ULTIMO_GAS_CAR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Control.h"
#include <string>

using namespace std;
using namespace sf;

class Car{

protected:
    double x_tmp, y_tmp;
    int speed;
    int clashes;
    float lenght;
    float width;
    int number;

public:
    Car();
    Control control;
    bool setMachinePlayer(int num_circuit, Sprite *S_MachinePlayer, Texture *T_MachinePlayer, float *x_CarPlayer, float *y_CarPlayer, double *degree_CarPlayer, double *degreeCost);
    void Car_Player(Sprite *S_MachinePlayer, float *CarPlayer_Acc, double *degree_CarPlayer, float *y_CarPlayer, float *x_CarPlayer, double *degreeConst, int num_circuit);
    void Car_PlayerAcc(double *degreeConst, float *CarPlayer_Acc, float *y_CarPlayer, float *x_CarPlayer, double *degree_CarPlayer, int num_circuit);
    void Car_PlayerAcc_Out(double *degreeConst, float *CarPlayer_Acc, float *y_CarPlayer, float *x_CarPlayer, double *degree_CarPlayer);
    void Car_PlayerRet(double *degreeConst, double *Degree_CarPlayer, float *y_CarPlayer, float *x_CarPlayer, int num_circuit);
    void Car_PlayerRet_Out(double *degreeConst, double *Degree_CarPlayer, float *y_CarPlayer, float *x_CarPlayer);
    void Car_PlayerRi(double *degree_CarPlayer);
    void Car_PlayerLe(double *degree_CarPlayer);
    int Type_Race, start;
    int Car_degree=0;
    float const_Acc=0.005, const_Brake=0.005;
};
class CarPlayer : public Car{
protected:
    bool carUpgrade;
public:
    void setSoundBehavior();
    void getSuoundBehavior();
    void setCarBehavior();
    bool getCarBehavior();
    void setUpgrade();
    void getUpgrade();
    void setBasetrajectory();
    bool getBasetrajectory();
    CarPlayer();
};
/* classe che definisce la macchina dell'utente
 */

class SoundBehavior : public CarPlayer{

protected:
    string TypeofSound;
public:
    void AlgorithmAcceleration();
    void AlgorithmBrake();
    void AlgorithmBase();
    SoundBehavior();
};
/* definizione della classe per il suono
 *
 */
class Basetrajectory : public CarPlayer{

public:
    void A_star();
};
/*
 * classe che definisce la traiettoria automatica del giocatore in caso di safety car
 */
class CarBehavior : public CarPlayer{

public:
    void Accelerates();
    void Restrains();
    void Reverse_gear();
    void GO_left();
    void GO_right();
    CarBehavior();
};
/* classe che definisce il comportamento della macchina in base all'utente
 *
 */
class Motore : public CarPlayer{
protected:
    int displacement;
public:
    int Upgrade_Displacement();
    Motore();
};
/* classe motore per upgrade macchina giocatore
 *
 */
class Telaio : public CarPlayer{

protected:
    int weight;
public:
    int Upgrade_Weight();
    Telaio();
};
/* classe telaio per upgrade macchina giocatore
 *
 */
class Carrozzeria : public CarPlayer{

protected:
    string Aerodynamics;
public:
    string Upgrade_Aerodynamics();
    Carrozzeria();
};
class CarsCPU : public Car{

public:
    CarsCPU();
    void setCpuStrategy();
    void getCpuStrategy();
protected:
    string model;
};
/* classe che definisce le varie macchine del computer
 *
 */
class SafetyCar : Car {

protected:
    string colour2;
    void setCpuStrategy();
    void getCpuStrategy();
public:
    SafetyCar();
};
/* classe che definisce la safety car
 *
 */
class CpuStrategy{

protected:
    bool OnSafetyCar;
    int Trajectory;
public:
    void A_star();
    int do_trajectory();
    bool get_SafetyCar();
    CpuStrategy();
};
class Trajectory : public CpuStrategy{

public:
    void A_star1();
    Trajectory();
};
class Trajectory_safetycar : public CpuStrategy{

public:
    void A_star2();
    Trajectory_safetycar();
};
class GeneralTrajectory : public CpuStrategy{

public:
    void A_star3();
    GeneralTrajectory();
};


#endif //ALL_ULTIMO_GAS_CAR_H
