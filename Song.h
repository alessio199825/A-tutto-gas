//
// Created by alessio on 05/03/19.
//

#ifndef ALL_ULTIMO_GAS_MUSIC_H
#define ALL_ULTIMO_GAS_MUSIC_H

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Error.h"
#include "Car.h"
#include "Control.h"


using namespace std;
using namespace sf;

class Song {

public:

    //creare una funzione che gestisca i team radio 4 e 10, ovvero i due team radio finali (team radio 4àvittoria,  team radio 10 àsconfitta).

    Song();

    void music_Load(RenderWindow &window, Error &error);
    void music_Menu(RenderWindow &window, Error &error);
    void stop_Menu();
    void music_Box(RenderWindow &window, Error &error);
    void stop_Box();
    void music_Race(RenderWindow &window, Error &error);
    void stop_Race();
    void pause_Race(bool Select_Pause);              //come Music_RadioPause fa sia la funzione di pausa che di play dopo la pausa, modificare il progetto completo di conseguenza
    void music_TrafficLight(RenderWindow &window, Error &error);
    void setTraffic_light(bool traffic_light);
    void setLightloop(bool lightloop);
    void MusicTime(Car &car, RenderWindow &window, Error &error, int num_circuit);
    void Music_Radio(RenderWindow &window, Error &error);     //eliminare teamradioloop da ogni .cpp in cui viene usato
    void Music_RadioPause(bool controlRadio);        // per gestire la pausa di un team radio in caso di break della corsa. Inserirla negli appositi punti.


private:

    Music music_load, music_menu, music_race, music_trafficlight, M_teamRadio, music_box;
    bool loadloop=false, menuloop=false, raceloop=false, lightloop=false, boxloop=false, traffic_light=false;
    int SelectRadio;
    float Radio_Seconds=20;
    Clock clockRadio;
    Time timeRadio;

};


#endif //ALL_ULTIMO_GAS_MUSIC_H
