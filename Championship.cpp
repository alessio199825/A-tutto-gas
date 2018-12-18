//
// Created by alessio on 20/10/18.
//
#include "Championship.h"
Championship::Championship() {
}
bool Championship::setChampionshipState(Texture *T_championship, Sprite *S_championship)  {
    if (!T_championship[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/90390.jpg")) {
        return true;
    }
    S_championship[0].setTexture(T_championship[0]);
    if (!T_championship[1].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/indietro.jpg")) {       //pulsante1
        return true;
    }
    S_championship[1].setTexture(T_championship[1]);
    S_championship[1].setPosition(sf::Vector2f(25, 25));
    if (!T_championship[2].loadFromFile("//home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/titolo carriera.png")) {       //pulsante2
        return true;
    }
    S_championship[2].setTexture(T_championship[2]);
    S_championship[2].setPosition(sf::Vector2f(220, 25));
    if (!T_championship[3].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/seleziona macchina.png")) {       //pulsante3
        return true;
    }
    S_championship[3].setTexture(T_championship[3]);
    S_championship[3].setPosition(sf::Vector2f(650, 170));
    if (!T_championship[4].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/macchina1.jpg")) {       //pulsante4
        return true;
    }
    S_championship[4].setTexture(T_championship[4]);
    S_championship[4].setPosition(sf::Vector2f(650, 270));
    if (!T_championship[5].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/macchina2.jpg")) {       //pulsante5
        return true;
    }
    S_championship[5].setTexture(T_championship[5]);
    S_championship[5].setPosition(sf::Vector2f(767.5, 270));
    if (!T_championship[6].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/macchina3.jpg")) {       //pulsante6
        return true;
    }
    S_championship[6].setTexture(T_championship[6]);
    S_championship[6].setPosition(sf::Vector2f(885, 270));
    return false;
}
int Championship::getQualifications(double& posx, double& posy, Texture *T_championship, Sprite *S_championship) {
    if (posx > 650 && posx < 735 && posy > 270 && posy < 452) {     //tasto macchina1
        if (!T_championship[7].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/macchina1on.jpg")) {       //circuito 1 modificato
            return -1;
        }
        S_championship[7].setTexture(T_championship[7]);
        S_championship[7].setPosition(sf::Vector2f(650, 270));
        chooseCar=1;
    }
    if (posx > 767.5 && posx < 852 && posy > 270 && posy < 452) {     //tasto macchina2
        if (!T_championship[8].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/macchina2on.jpg")) {       //circuito 1 modificato
            return -1;
        }
        S_championship[8].setTexture(T_championship[8]);
        S_championship[8].setPosition(sf::Vector2f(767.5, 270));
        chooseCar=2;
    }
    if (posx > 885 && posx < 970 && posy > 270 && posy < 452) {     //tasto macchina3
        if (!T_championship[9].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Championship/macchina3on.jpg")) {       //circuito 1 modificato
            return -1;
        }
        S_championship[9].setTexture(T_championship[9]);
        S_championship[9].setPosition(sf::Vector2f(885, 270));
        chooseCar=3;
    }
    return chooseCar;
}
int Championship::Return(double &posx, double &posy) {
    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        return 0;
    }
    return 1;
}