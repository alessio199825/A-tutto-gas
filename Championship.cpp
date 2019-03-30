//
// Created by alessio on 20/10/18.
//
#include "Championship.h"

void Championship::setChampionshipState(RenderWindow &window, Error &error)  {

    try {
        if (!T_championship[0].loadFromFile("Championship/90390.jpg")) {
            throw "impossibile caricare Texture";
        }
        S_championship[0].setTexture(T_championship[0]);
        if (!T_championship[1].loadFromFile("Championship/indietro.jpg")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_championship[1].setTexture(T_championship[1]);
        S_championship[1].setPosition(sf::Vector2f(25, 25));
        if (!T_championship[2].loadFromFile("Championship/titolo carriera.png")) {       //pulsante2
            throw "impossibile caricare Texture";
        }
        S_championship[2].setTexture(T_championship[2]);
        S_championship[2].setPosition(sf::Vector2f(220, 25));
        if (!T_championship[3].loadFromFile("Championship/seleziona macchina.png")) {       //pulsante3
            throw "impossibile caricare Texture";
        }
        S_championship[3].setTexture(T_championship[3]);
        S_championship[3].setPosition(sf::Vector2f(650, 170));
        if (!T_championship[4].loadFromFile("Championship/macchina1.jpg")) {       //pulsante4
            throw "impossibile caricare Texture";
        }
        S_championship[4].setTexture(T_championship[4]);
        S_championship[4].setPosition(sf::Vector2f(650, 270));
        if (!T_championship[5].loadFromFile("Championship/macchina2.jpg")) {       //pulsante5
            throw "impossibile caricare Texture";
        }
        S_championship[5].setTexture(T_championship[5]);
        S_championship[5].setPosition(sf::Vector2f(767.5, 270));
        if (!T_championship[6].loadFromFile("Championship/macchina3.jpg")) {       //pulsante6
            throw "impossibile caricare Texture";
        }
        S_championship[6].setTexture(T_championship[6]);
        S_championship[6].setPosition(sf::Vector2f(885, 270));
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }

    for (int i = 0; i < 7; i++) {
        window.draw(S_championship[i]);
    }

}

int Championship::getQualifications(double posx, double posy, RenderWindow &window, Error &error) {

    try {
        if (posx > 650 && posx < 735 && posy > 270 && posy < 452) {     //tasto macchina1
            if (!T_championship[7].loadFromFile("Championship/macchina1on.jpg")) {       //circuito 1 modificato
                throw "impossibile caricare Texture";
            }
            S_championship[7].setTexture(T_championship[7]);
            S_championship[7].setPosition(sf::Vector2f(650, 270));
            chooseCar = 1;
        }
        if (posx > 767.5 && posx < 852 && posy > 270 && posy < 452) {     //tasto macchina2
            if (!T_championship[8].loadFromFile("Championship/macchina2on.jpg")) {       //circuito 1 modificato
                throw "impossibile caricare Texture";
            }
            S_championship[8].setTexture(T_championship[8]);
            S_championship[8].setPosition(sf::Vector2f(767.5, 270));
            chooseCar = 2;
        }
        if (posx > 885 && posx < 970 && posy > 270 && posy < 452) {     //tasto macchina3
            if (!T_championship[9].loadFromFile("Championship/macchina3on.jpg")) {       //circuito 1 modificato
                throw "impossibile caricare Texture";
            }
            S_championship[9].setTexture(T_championship[9]);
            S_championship[9].setPosition(sf::Vector2f(885, 270));
            chooseCar = 3;
        }
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }

    switch (chooseCar) {
        case 1:
            window.draw(S_championship[7]);
            break;
        case 2:
            window.draw(S_championship[8]);
            break;
        case 3:
            window.draw(S_championship[9]);
            break;
        default:
            break;
    }

    return chooseCar;
}

int Championship::Return(double posx, double posy) {

    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        return 0;
    }
    return 1;
}


Championship::~Championship()= default;

Championship::Championship() = default;


