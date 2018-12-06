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

protected:
    int Ranking;
    int Qualifications;
    int chooseCar;

public:
    Championship();

    bool setChampionshipState(Texture *T_championship, Sprite *S_championship);
    int getQualifications(double& posx, double& posy, Texture *T_championship, Sprite *S_championship);
    int Championship_Return(double& posx, double& posy);
};


#endif //ALL_ULTIMO_GAS_CHAMPIONSHIP_H
