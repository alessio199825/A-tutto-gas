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

    void CreateMap();
    int TileNumber(int i, int j);

    virtual ~Tilemaps();

private:

    char numCircuit;
    fstream mapLevel;
    vector <vector <int>> lineTiles;

};


#endif //ALL_ULTIMO_GAS_TILEMAPS_H
