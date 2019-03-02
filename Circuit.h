#ifndef PROGETTO_CIRCUIT_H
#define PROGETTO_CIRCUIT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class Circuit {

public:
    Circuit();

    bool setTileMaps(RenderWindow &window, int circuiton);

    const Sprite getS_Pause(int i) const;

    int getTileMaps();
    int getTile();
    const Sprite getS_tilemaps() const;
    virtual ~Circuit();

protected:
    int length;
    int number_of_curves;
    string difficult;
    string name;
    float record_lap;
    int number_race;

private:

    Texture T_Pause[2];
    Sprite S_Pause[2];
    Sprite S_tilemaps;
    Texture T_tilemaps;
};

#endif //PROGETTO_CIRCUIT_H