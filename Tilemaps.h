//
// Created by alessio on 17/06/19.
//

#ifndef ALL_ULTIMO_GAS_TILEMAPS_H
#define ALL_ULTIMO_GAS_TILEMAPS_H


#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;

class Tilemaps {

public:

    Tilemaps();

    void CreateMap1();
    void CreateMap2();
    void CreateMap3();
    int TileNumber(int i, int j);

private:

    fstream mapLevel1;
    vector <vector <int>> lineTiles;

};


#endif //ALL_ULTIMO_GAS_TILEMAPS_H
