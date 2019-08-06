//
// Created by alessio on 19/03/19.
//

#include "LoadMenu_Page.h"
#include "Menu_Game.h"
#include "Load_Exception.h"

LoadMenu_Page::LoadMenu_Page(RenderWindow &window, Error &error) {

    setWindow(error, window);
    song.music_Load(window, error);
    pageIndex=-1;

}

LoadMenu_Page::~LoadMenu_Page() = default;

int LoadMenu_Page::getActivities(Event event, RenderWindow &window) {

    switch(event.type) {

        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                    window.close();
                    break;

                case Keyboard::Tab:                         //con il tasto tab viene saltato il caricamento
                    pageIndex = 0;
                    pageChanged=true;
                    return 0;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    time_load = C_load.getElapsedTime();

    if(time_load.asSeconds()>24 || pageIndex==0){       //consente di saltare il caricamento dopo 24 secondi oppure dopo aver premuto il tasto tab
        pageIndex=0;
        pageChanged=true;
        return 0;
    }

    return -1;

}

void LoadMenu_Page::setWindow(Error &error, RenderWindow &window) {

    try{
        if (!T_load[0].loadFromFile("Load/loading.jpg"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_load[0].setTexture(T_load[0]);

        if (!T_load[1].loadFromFile("Load/caricamento.png"))
            throw Load_exception("Load_exception:Impossibile caricare file");

        S_load[1].setTexture(T_load[1]);
    }

    catch(Load_exception e){
        error.Check_Image(window);
    }

}

Menu_State *LoadMenu_Page::getNewPage(RenderWindow &window, Error &error) {

    switch(pageIndex){
        case 0:
            return new Menu_Game(window, error);
    }

}

void LoadMenu_Page::draw(RenderWindow &window) {

    degree_load=degree_load+0.5;
    S_load[1].setPosition(sf::Vector2f(240, 350));
    S_load[1].setOrigin(sf::Vector2f(50, 50));
    S_load[1].setRotation(static_cast<float>(degree_load));

    for (const auto&i : S_load)
        window.draw(i);
}
