#ifndef PROGETTO_CIRCUIT_H
#define PROGETTO_CIRCUIT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "Error.h"

using namespace std;
using namespace sf;

class Circuit {

public:

    Circuit();

    void setTileMaps(int circuitrace, Error &error, RenderWindow &window, int Type_race);
    const Sprite getS_Pause(int i) const;
    const Sprite getS_tilemaps() const;

    virtual ~Circuit();


private:

    Texture T_Pause[2];
    Sprite S_Pause[2];
    Sprite S_tilemaps;
    Texture T_tilemaps;
};

#endif //PROGETTO_CIRCUIT_H