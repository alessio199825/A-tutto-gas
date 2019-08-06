//
// Created by alessio on 20/10/18.
//
#ifndef ALL_ULTIMO_GAS_CHAMPIONSHIP_H
#define ALL_ULTIMO_GAS_CHAMPIONSHIP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;
using namespace std;

class Championship {

public:

    Championship();
    void setChampionshipState(RenderWindow &window, Error &error) throw(char);
    int getQualifications(double posx, double posy, RenderWindow &window, Error &error);
    int Return(double posx, double posy);

    ~Championship();


private:

    int chooseCar;
    Texture T_championship[10];
    Sprite S_championship[10];

};
#endif //ALL_ULTIMO_GAS_CHAMPIONSHIP_H