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

    bool setTileMaps(int circuiton, Sprite *S_tilemaps, Texture *T_tilemaps, Sprite *S_Pause, Texture *T_Pause);
    int getTileMaps();
    bool setWeather();
    bool getWeather();
    int getTile();

    virtual ~Circuit();

protected:

    int length;
    int number_of_curves;
    string difficult;
    string name;
    float record_lap;
    int number_race;

};

/*
class WeatherBehavior{

public:
    WeatherBehavior();

protected:
    int Do_weather();
};

class Sun : public WeatherBehavior{

public:
    Sun();

protected:
    void Do_weather();
};

class Rain : public WeatherBehavior{
public:
    Rain();

protected:
    void Do_weather1();
};
*/



#endif //PROGETTO_CIRCUIT_H