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
    bool setMachinePlayer(RenderWindow &window, int num_circuit);
    void Car_Player_Movement(RenderWindow &window, int num_circuit);
    void Accelerate();
    void Accelerate_Out();
    void Do_Reverse();
    void Do_Reverse_Out();
    void Turn_Right();
    void Turn_Left();
    float getY_CarPlayer() const;
    float getX_CarPlayer() const;

    double degree_CarPlayer;
    float y_CarPlayer, x_CarPlayer;
    int Type_Race, start;
    int Car_degree=0;
    float const_Acc=0.010, const_Brake=0.005;


private:

    float CarPlayer_Acc=1;
    Sprite S_MachinePlayer;
    Texture T_MachinePlayer;
    double degreeConst;

};
/*
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
*/
/* classe che definisce la macchina dell'utente
 *//*


*/
/*class SoundBehavior : public CarPlayer{

protected:
    string TypeofSound;
public:
    void AlgorithmAcceleration();
    void AlgorithmBrake();
    void AlgorithmBase();
    SoundBehavior();
};
*//*
*/
/* definizione della classe per il suono
 *
 *//*

class Basetrajectory : public CarPlayer{

public:
    void A_star();
};
*/
/*
 * classe che definisce la traiettoria automatica del giocatore in caso di safety car
 *//*

class Motore : public CarPlayer{
protected:
    int displacement;
public:
    int Upgrade_Displacement();
    Motore();
};
*/
/* classe motore per upgrade macchina giocatore

 *//*

class Telaio : public CarPlayer{

protected:
    int weight;
public:
    int Upgrade_Weight();
    Telaio();
};
*/
/* classe telaio per upgrade macchina giocatore
 *
 *//*

class Carrozzeria : public CarPlayer{

protected:
    string Aerodynamics;
public:
    string Upgrade_Aerodynamics();
    Carrozzeria();
};


class SafetyCar : Car {

protected:
    string colour2;
    void setCpuStrategy();
    void getCpuStrategy();
public:
    SafetyCar();
};
*/
/* classe che definisce la safety car
 *
 *//*

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

*/
#endif //ALL_ULTIMO_GAS_CAR_H

