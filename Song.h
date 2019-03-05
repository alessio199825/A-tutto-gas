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

using namespace std;
using namespace sf;

class Song {

public:
    Song();
    void music_Load(RenderWindow &window, Error &error);
    void music_Menu(RenderWindow &window, Error &error);
    void stop_Load();
    void stop_Menu();
    //ciao

private:
    Music music_load, music_menu;
    bool loadloop=false, menuloop=false;

};


#endif //ALL_ULTIMO_GAS_MUSIC_H
