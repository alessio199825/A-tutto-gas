//
// Created by alessio on 20/10/18.
//
#ifndef ALL_ULTIMO_GAS_CHAMPIONSHIP_H
#define ALL_ULTIMO_GAS_CHAMPIONSHIP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Championship {

public:

    Championship();
    bool setChampionshipState();
    int getQualifications(double posx, double posy);
    const Sprite getS_championship(int i) const;


    int Return(double posx, double posy);

    ~Championship();

protected:
    int Ranking;
    int Qualifications;
    int chooseCar;

private:
    Texture T_championship[10];
    Sprite S_championship[10];
};
#endif //ALL_ULTIMO_GAS_CHAMPIONSHIP_H