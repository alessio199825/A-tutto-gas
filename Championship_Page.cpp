//
// Created by alessio on 16/03/19.
//

#include "Championship_Page.h"
#include "Menu_Game.h"

Championship_Page::Championship_Page(RenderWindow &window, Error &error) {

    setWindow(error, window);

}

Championship_Page::~Championship_Page() {

}

void Championship_Page::draw(RenderWindow &window) {

    for(int i=0; i<7; i++){
        window.draw(S_championship[i]);
    }

    switch(chooseCar){

        case 1:
            window.draw(S_championship[7]);
            break;

        case 2:
            window.draw(S_championship[8]);
            break;

        case 3:
            window.draw(S_championship[9]);
            break;
        default:break;
    }

}

int Championship_Page::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;

                case Keyboard::BackSpace:                         //con il tasto Return torniamo al manu principale
                    pageIndex = 0;
                    pageChanged=true;
                    return 0;
                default:
                    break;
            }
            break;
        case Event::MouseButtonReleased:

            if (Mouse::getPosition(window).x  > 25 && Mouse::getPosition(window).x  < 125
                && Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 115) {
                pageIndex=0;
                pageChanged=true;
                return 0;
            }

            if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 735 &&
                Mouse::getPosition(window).y > 270 && Mouse::getPosition(window).y < 452) {
                chooseCar = 1;
            }

            if (Mouse::getPosition(window).x > 767 && Mouse::getPosition(window).x < 852 &&
                Mouse::getPosition(window).y > 270 && Mouse::getPosition(window).y < 452) {
                chooseCar = 2;
            }

            if (Mouse::getPosition(window).x > 885 && Mouse::getPosition(window).x < 970 &&
                Mouse::getPosition(window).y > 270 && Mouse::getPosition(window).y < 452) {
                chooseCar = 3;
            }
        default:
            break;
    }

    return 0;
}


void Championship_Page::setWindow(Error &error, RenderWindow &window) {

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

        if (!T_championship[7].loadFromFile("Championship/macchina1on.jpg")) {       //circuito 1 modificato
            throw "impossibile caricare Texture";
        }
        S_championship[7].setTexture(T_championship[7]);
        S_championship[7].setPosition(sf::Vector2f(650, 270));

        if (!T_championship[8].loadFromFile("Championship/macchina2on.jpg")) {       //circuito 1 modificato
            throw "impossibile caricare Texture";
        }
        S_championship[8].setTexture(T_championship[8]);
        S_championship[8].setPosition(sf::Vector2f(767.5, 270));

        if (!T_championship[9].loadFromFile("Championship/macchina3on.jpg")) {       //circuito 1 modificato
            throw "impossibile caricare Texture";
        }
        S_championship[9].setTexture(T_championship[9]);
        S_championship[9].setPosition(sf::Vector2f(885, 270));
    }
    catch(...) {
        error.Check_Image(window);
    }

    tilemaps.CreateMap1();
    //cout<<tilemaps.TileNumber(10, 3)<<endl;
}

Menu_State *Championship_Page::getNewPage(RenderWindow &window, Error &error) {

    switch(pageIndex){
        case 0:
            return new Menu_Game(window, error);
        default:break;
    }

}
