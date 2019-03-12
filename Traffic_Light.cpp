//
// Created by alessio on 05/03/19.
//

#include "Traffic_Light.h"

Traffic_Light::Traffic_Light() {

}

bool Traffic_Light::Light_On(RenderWindow &window, Error &error) {


    if(control_light){
        light_clock.restart();
        control_light=false;
    }

    light_time= light_clock.getElapsedTime();

    if(light_time.asSeconds() > 7){
        song.setTraffic_light(false);
        return true;
    }

    try {
        if (!T_Light[0].loadFromFile("Semaforo/semaforospento.png")) {
            throw "impossibile caricare Texture";
        }
        S_Light[0].setTexture(T_Light[0]);
        S_Light[0].setPosition(sf::Vector2f(500, 300));
        S_Light[0].setOrigin(sf::Vector2f(176, 108));

        if (!T_Light[1].loadFromFile("Semaforo/semaforo1.png")) {
            throw "impossibile caricare Texture";
        }
        S_Light[1].setTexture(T_Light[1]);
        S_Light[1].setPosition(sf::Vector2f(500, 300));
        S_Light[1].setOrigin(sf::Vector2f(176, 108));

        if (!T_Light[2].loadFromFile("Semaforo/semaforo2.png")) {
            throw "impossibile caricare Texture";
        }
        S_Light[2].setTexture(T_Light[2]);
        S_Light[2].setPosition(sf::Vector2f(500, 300));
        S_Light[2].setOrigin(sf::Vector2f(176, 108));

        if (!T_Light[3].loadFromFile("Semaforo/semaforo3.png")) {
            throw "impossibile caricare Texture";
        }
        S_Light[3].setTexture(T_Light[3]);
        S_Light[3].setPosition(sf::Vector2f(500, 300));
        S_Light[3].setOrigin(sf::Vector2f(176, 108));

        if (!T_Light[4].loadFromFile("Semaforo/semaforo4.png")) {
            throw "impossibile caricare Texture";
        }
        S_Light[4].setTexture(T_Light[4]);
        S_Light[4].setPosition(sf::Vector2f(500, 300));
        S_Light[4].setOrigin(sf::Vector2f(176, 108));

        if (!T_Light[5].loadFromFile("Semaforo/semaforoacceso.png")) {
            throw "impossibile caricare Texture";
        }
        S_Light[5].setTexture(T_Light[5]);
        S_Light[5].setPosition(sf::Vector2f(500, 300));
        S_Light[5].setOrigin(sf::Vector2f(176, 108));

    }

    catch(...){
        window.close();
        error.Check_Image();
    }

    if(light_time.asSeconds()<2)
        window.draw(S_Light[0]);

    if(light_time.asSeconds()>2 && light_time.asSeconds()<3)
        window.draw(S_Light[1]);

    if(light_time.asSeconds()>3 && light_time.asSeconds()<4)
        window.draw(S_Light[2]);

    if(light_time.asSeconds()>4 && light_time.asSeconds()<5)
        window.draw(S_Light[3]);

    if(light_time.asSeconds()>5 && light_time.asSeconds()<6)
        window.draw(S_Light[4]);

    if(light_time.asSeconds()>6 && light_time.asSeconds()<7)
        window.draw(S_Light[5]);

    return false;

}

void Traffic_Light::setControl_light(bool control_light) {
    Traffic_Light::control_light = control_light;
}
