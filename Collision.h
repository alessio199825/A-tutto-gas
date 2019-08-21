//
// Created by alessio on 09/08/19.
//

#ifndef ALL_ULTIMO_GAS_COLLISION_H
#define ALL_ULTIMO_GAS_COLLISION_H

#include "Load_Exception.h"
#include "Error.h"
#include "BitmaskManager .h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>

class Collision {

public:
    Collision();

    bool Cpu_Menagement(int CpuCar);

    bool CarPlayer_Menagement();

    bool CarPlayer_Reverse();

    void set_sCarCpu(Sprite sCpuBox1[], Sprite CpuBox2[]);

    bool PixelPerfectTest(const sf::Sprite& Object1 ,const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);

    bool CreateTextureAndBitmask(sf::Texture &LoadInto, const std::string& Filename);

    void setSCar(Sprite &sBox1, Sprite &sBox2);

private:

    Sprite  S_CpuBox1[5], S_CpuBox2[5];
    Sprite S_CarBox1, S_CarBox2;
    BitmaskManager Bitmasks;

};

#endif //ALL_ULTIMO_GAS_COLLISION_H
