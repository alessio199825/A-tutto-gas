//
// Created by alessio on 16/05/19.
//

#include "Control_Cpu.h"
#include <SFML/Graphics.hpp>

void Control_Cpu::LoadControlMap(RenderWindow &window, Error &error, int numcircuit) {

    /*try {
        if(!map) {
            switch (numcircuit) {
                case 1:
                    if (!ControlMap.loadFromFile("Control/controllo_astar1.bmp")) {
                        throw "impossibile caricare Texture";
                    }
                    break;
                case 2:
                    if (!ControlMap.loadFromFile("Control/controllo_astar2.bmp")) {
                        throw "impossibile caricare Texture";
                    }
                    break;
                case 3:
                    if (!ControlMap.loadFromFile("Control/controllo_astar3.bmp")) {
                        throw "impossibile caricare Texture";
                    }
                    break;
                default:
                    break;
            }

            map=true;
        }
        if(!example)
        if (!ExampleColor.loadFromFile("Control/controllo_astar1.bmp")) {
            throw "impossibile caricare Texture";
        }
        example=true;
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }*/

}


int Control_Cpu::GetCostNode(int x, int y) {

        if (!map) {
            if (!ControlMap.loadFromFile("Control/controllo_astar1.bmp")) {
                throw "impossibile caricare Texture";
            }

            if (!ExampleColor.loadFromFile("Control/controllo_astar1.bmp")) {
                throw "impossibile caricare Texture";
            }

            map = true;

        }

    Rosso = ExampleColor.getPixel(80, 90);
    Nero=ExampleColor.getPixel(290, 270);
    Giallo=ExampleColor.getPixel(153, 270);
    Colore=ControlMap.getPixel(static_cast<unsigned int>(x), static_cast<unsigned int>(y));

    if(Colore==Nero||Colore==Rosso)
        return 9;
    else if(Colore==Giallo)
        return 2;
    else
        return 1;
}




