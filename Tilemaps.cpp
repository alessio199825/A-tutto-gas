//
// Created by alessio on 17/06/19.
//

#include <iostream>
#include <sstream>
#include "Tilemaps.h"

void Tilemaps::CreateMap() {

    ifstream OpenFile("Control/circuitNum.txt");
    OpenFile.get(numCircuit);
    OpenFile.close();

        switch (numCircuit) {
            case '1':
                mapLevel.open("Control/level1.txt");
                break;
            case '2':
                mapLevel.open("Control/level2.txt");
                break;
            case '3':
                mapLevel.open("Control/level3.txt");
                break;
            default:
                break;
        }

        int i = 0;
        string line;
        vector<int> Tile;
        while (getline(mapLevel, line)) {

            istringstream iss(line);
            while (iss >> i) {

                Tile.push_back(i);
            }

            lineTiles.push_back(Tile);
            Tile.clear();
        }

    mapLevel.close();
}

int Tilemaps::TileNumber(int i, int j) {

    return lineTiles[j/20][i/20];
}

Tilemaps::~Tilemaps() = default;

Tilemaps::Tilemaps() = default;

