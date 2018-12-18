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
    void Check_Image(Texture *T_Error, Sprite *S_Error);
    void Check_Sound(Texture *T_Error, Sprite *S_Error);

};

#endif //PROJECT_ERROR_H
