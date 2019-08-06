//
// Created by alessio on 16/03/19.
//

#include "SingleRace_Page.h"
#include "SingleRace_Page2.h"
#include "Menu_Game.h"
#include "Load_Exception.h"


SingleRace_Page::SingleRace_Page(RenderWindow &window, Error &error) {

    setWindow(error, window);

}

SingleRace_Page::~SingleRace_Page() = default;

void SingleRace_Page::draw(RenderWindow &window) {

    for(int i=0; i<10; i++){
        window.draw(S_singlerace[i]);
    }

    switch(lap){
        case 3:
            window.draw(S_singlerace[10]);
            break;
        case 5:
            window.draw(S_singlerace[11]);
            break;
        case 10:
            window.draw(S_singlerace[12]);
            break;
        default:break;
    }

    switch(weath){
        case 0:
            window.draw(S_singlerace[13]);
            break;
        case 1:
            window.draw(S_singlerace[14]);
            break;
        default:break;
    }

}

int SingleRace_Page::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;

                case Keyboard::BackSpace:                         //con il tasto Return torniamo al manu principale
                    pageIndex = 0;
                    pageChanged=true;
                    break;
                default:
                    break;
            }
            break;
        case Event::MouseButtonReleased:

            if (Mouse::getPosition(window).x  > 50 && Mouse::getPosition(window).x  < 139
                && Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 384) {
                lap = 3;
            }

            if (Mouse::getPosition(window).x > 159 && Mouse::getPosition(window).x < 248 &&
                Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 384) {
                lap = 5;
            }

            if (Mouse::getPosition(window).x > 268 && Mouse::getPosition(window).x < 357 &&
                Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 384) {
                lap = 10;
            }

            if (Mouse::getPosition(window).x > 389 && Mouse::getPosition(window).x < 475 &&
                Mouse::getPosition(window).y > 420 && Mouse::getPosition(window).y < 509) {
                weath = 0;
            }

            if (Mouse::getPosition(window).x > 495 && Mouse::getPosition(window).x < 581 &&
                Mouse::getPosition(window).y > 420 && Mouse::getPosition(window).y < 509) {
                weath = 1;
            }


            if (Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 920 &&
                Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 115) {             //tasto avanti
                pageIndex = 3;
                pageChanged=true;
            }

            if (Mouse::getPosition(window).x > 25 && Mouse::getPosition(window).x < 125 &&
                Mouse::getPosition(window).y > 25 && Mouse::getPosition(window).y < 115) {
                pageIndex = 0;
                pageChanged=true;
            }
            break;
        default:
            break;
    }


    return 0;
}

void SingleRace_Page::setWindow(Error &error, RenderWindow &window) {

    try {

        if (!T_singlerace[0].loadFromFile("Single_Race/gara singola.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[0].setTexture(T_singlerace[0]);

        if (!T_singlerace[1].loadFromFile("Single_Race/indietro.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[1].setTexture(T_singlerace[1]);
        S_singlerace[1].setPosition(sf::Vector2f(25, 25));

        if (!T_singlerace[2].loadFromFile("Single_Race/numero di giri.png")) {       //scritta numero giri
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[2].setTexture(T_singlerace[2]);
        S_singlerace[2].setPosition(sf::Vector2f(50, 200));

        if (!T_singlerace[3].loadFromFile("Single_Race/ok3.jpg")) {       //3 giri
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[3].setTexture(T_singlerace[3]);
        S_singlerace[3].setPosition(sf::Vector2f(50, 300));

        if (!T_singlerace[4].loadFromFile("Single_Race/ok5.jpg")) {       //5 giri
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[4].setTexture(T_singlerace[4]);
        S_singlerace[4].setPosition(sf::Vector2f(159, 300));

        if (!T_singlerace[5].loadFromFile("Single_Race/ok10.jpg")) {       //10 giri
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[5].setTexture(T_singlerace[5]);
        S_singlerace[5].setPosition(sf::Vector2f(268, 300));

        if (!T_singlerace[6].loadFromFile("Single_Race/meteo.png")) {       //meteo
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[6].setTexture(T_singlerace[6]);
        S_singlerace[6].setPosition(sf::Vector2f(50, 420));

        if (!T_singlerace[7].loadFromFile("Single_Race/sole.jpg")) {       //sole
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[7].setTexture(T_singlerace[7]);
        S_singlerace[7].setPosition(sf::Vector2f(389, 420));

        if (!T_singlerace[8].loadFromFile("Single_Race/pioggia.jpg")) {       //pioggia
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[8].setTexture(T_singlerace[8]);
        S_singlerace[8].setPosition(sf::Vector2f(495, 420));

        if (!T_singlerace[9].loadFromFile("Single_Race/avanti1.png")) {       //avanti
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[9].setTexture(T_singlerace[9]);
        S_singlerace[9].setPosition(sf::Vector2f(600, 25));

        if (!T_singlerace[10].loadFromFile("Single_Race/ok3on.jpg")) {       //3 giri modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[10].setTexture(T_singlerace[10]);
        S_singlerace[10].setPosition(sf::Vector2f(50, 300));

        if (!T_singlerace[11].loadFromFile("Single_Race/ok5on.jpg")) {       //5 giri modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[11].setTexture(T_singlerace[11]);
        S_singlerace[11].setPosition(sf::Vector2f(159, 300));

        if (!T_singlerace[12].loadFromFile("Single_Race/ok10on.jpg")) {       //10 giri modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[12].setTexture(T_singlerace[12]);
        S_singlerace[12].setPosition(sf::Vector2f(268, 300));

        if (!T_singlerace[13].loadFromFile("Single_Race/soleon.jpg")) {       //sole modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[13].setTexture(T_singlerace[13]);
        S_singlerace[13].setPosition(sf::Vector2f(389, 420));

        if (!T_singlerace[14].loadFromFile("Single_Race/pioggia on.jpg")) {       //pioggia modificato
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_singlerace[14].setTexture(T_singlerace[14]);
        S_singlerace[14].setPosition(sf::Vector2f(495, 420));

    }
    catch(Load_exception e) {
        error.Check_Image(window);
    }

}

Menu_State *SingleRace_Page::getNewPage(RenderWindow &window, Error &error) {

    switch(pageIndex) {
        case 0:
            return new Menu_Game(window, error);
        case 3:
            return new SingleRace_Page2(window, error, weath, lap);
        default:break;
    }

    return 0;

}
