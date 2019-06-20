//
// Created by alessio on 17/06/19.
//

#include <iostream>
#include <sstream>
#include "Tilemaps.h"

void Tilemaps::CreateMap1() {

    mapLevel1.open("Control/level1.txt");

    int i=0;
    string line;
    vector <int> Tile;
    while(getline(mapLevel1,line)) {

        istringstream iss(line);
        while(iss>>i) {

            Tile.push_back(i);
        }

        lineTiles.push_back(Tile);
        Tile.clear();
    }
    mapLevel1.close();
}

void Tilemaps::CreateMap2() {

    mapLevel1.open("Control/level1.txt");       //da cambiare il nome del file di testo

    int i=0;
    string line;
    vector <int> Tile;
    while(getline(mapLevel1,line)) {

        istringstream iss(line);
        while(iss>>i) {

            Tile.push_back(i);
        }

        lineTiles.push_back(Tile);
        Tile.clear();
    }
    mapLevel1.close();
}

void Tilemaps::CreateMap3() {

    mapLevel1.open("Control/level1.txt");       //da cambiare il nome del file di testo

    int i=0;
    string line;
    vector <int> Tile;
    while(getline(mapLevel1,line)) {

        istringstream iss(line);
        while(iss>>i) {

            Tile.push_back(i);
        }

        lineTiles.push_back(Tile);
        Tile.clear();
    }
    mapLevel1.close();
}

int Tilemaps::TileNumber(int i, int j) {
    return lineTiles[i%20][j%20];
}

Tilemaps::Tilemaps() {
    
}
