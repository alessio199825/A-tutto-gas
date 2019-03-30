#include <iostream>
#include "Menu_Loop.h"
#include "Menu.h"
#include "Error.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>


int main() {

    //Menu ml;
    Menu_Loop menu_Loop;
    Error error;
    menu_Loop.generateWindow(error);
};
