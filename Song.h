//
// Created by alessio on 05/03/19.
//

#ifndef ALL_ULTIMO_GAS_MUSIC_H
#define ALL_ULTIMO_GAS_MUSIC_H

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Error.h"
#include "Car.h"
#include "Control.h"

using namespace std;
using namespace sf;

class Song {

public:
    Song();
    void music_Load(RenderWindow &window, Error &error);
    void stop_Load();
    void music_Menu(RenderWindow &window, Error &error);
    void stop_Menu();
    void music_Race(RenderWindow &window, Error &error);
    void play_Race();
    void stop_Race();
    void pause_Race();
    void music_TrafficLight(RenderWindow &window, Error &error);
    void setLightloop(bool lightloop);
    void music_TeamRadio(RenderWindow &window, Error &error);
    void music_Box(RenderWindow &window, Error &error);
    void MusicTime(Car &car, RenderWindow &window, Error &error, int num_circuit);
    void stop_Box();

    void setTraffic_light(bool traffic_light);

private:

    Music music_load, music_menu, music_race, music_trafficlight, music_teamradio[11], music_box;
    bool loadloop=false, menuloop=false, raceloop=false, lightloop=false, teamradioloop=false, boxloop=false, traffic_light=false;;

};


#endif //ALL_ULTIMO_GAS_MUSIC_H
