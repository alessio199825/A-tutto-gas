//
// Created by alessio on 19/03/19.
//

#include "Load_Page.h"
#include "Load_Exception.h"

Load_Page::Load_Page(RenderWindow &window, Error &error, int circuitrace, int Type_race, int meteo, int giri, int chooseCar) {
    x_Tyre=20;
    setWindow(error, window);
    num_circuit=circuitrace;
    Race_type=Type_race;
    weath=meteo;
    lap=giri;
    colore_macchina = chooseCar;
    if(num_circuit==0){
        num_circuit=3;
    }

}

Load_Page::~Load_Page() = default;

void Load_Page::draw(RenderWindow &window) {

    if(x_Tyre<800) {
        x_Tyre = static_cast<float>(x_Tyre + 0.25);
        degree_Tyre = degree_Tyre + 1;
    }
    S_planisphere[1].setPosition(Vector2f(x_Tyre, 387));
    S_planisphere[2].setPosition(Vector2f(x_Tyre + 22, 462));
    S_planisphere[2].setRotation(degree_Tyre);
    S_planisphere[3].setPosition(Vector2f(x_Tyre + 144, 462));
    S_planisphere[3].setRotation(degree_Tyre);

    for (const auto &i : S_planisphere)
        window.draw(i);
}

int Load_Page::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:
            switch (event.key.code) {

                case Keyboard::Escape:
                    window.close();
                    break;

                case Keyboard::Tab:
                    start_Race=true;
                    pageChanged=true;
                    return -1;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    if(x_Tyre>=800){
        start_Race=true;
        pageChanged=true;
        return -1;
    }

    return 0;

}

void Load_Page::setWindow(Error &error, RenderWindow &window) {

    try {
        if (!T_planisphere[0].loadFromFile("Single_Race/planisfero.png")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_planisphere[0].setTexture(T_planisphere[0]);

        if (!T_planisphere[1].loadFromFile("Load/fone.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_planisphere[1].setTexture(T_planisphere[1]);
        S_planisphere[1].setPosition(Vector2f(x_Tyre, 387));

        if (!T_planisphere[2].loadFromFile("Load/ruotona.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_planisphere[2].setTexture(T_planisphere[2]);
        S_planisphere[2].setPosition(Vector2f(x_Tyre + 22, 462));

        S_planisphere[2].setOrigin(13, 13);
        S_planisphere[2].setRotation(degree_Tyre);

        if (!T_planisphere[3].loadFromFile("Load/ruotona.png")) {
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_planisphere[3].setTexture(T_planisphere[3]);

        S_planisphere[3].setOrigin(13, 13);

    }
    catch(Load_exception e){
        error.Check_Image(window);
    }


}

Menu_State *Load_Page::getNewPage(RenderWindow &window, Error &error) {

    if(start_Race){
        return new Race_Page(window, error, num_circuit, Race_type, weath, lap, colore_macchina);
    }

    return 0;

}
