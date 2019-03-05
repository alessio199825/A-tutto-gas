#ifndef PROJECT_ERROR_H
#define PROJECT_ERROR_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Error {

public:

    Error();

    RenderWindow window_error;
    Event event_error;

    void Check_Image();
    void Check_Sound();

    //creare un errore per il mancato caricamento di una font

private:

    Texture T_Error[2];
    Sprite S_Error[2];

};

#endif //PROJECT_ERROR_H
