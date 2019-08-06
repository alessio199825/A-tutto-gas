#ifndef PROJECT_ERROR_H
#define PROJECT_ERROR_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Error{

public:

    Error();

    RenderWindow window_error;
    Event event_error;


    void Check_Image(RenderWindow &window);
    void Check_Sound();

private:

    Texture T_Error[2];
    Sprite S_Error[2];

};

#endif //PROJECT_ERROR_H
