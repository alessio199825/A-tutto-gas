//
// Created by alessio on 05/03/19.
//

#include "Traffic_Light.h"
#include "Load_Exception.h"

Traffic_Light::Traffic_Light() {

    control_trafficlight=true;

}

bool Traffic_Light::Light_On(RenderWindow &window, Error &error, int Type_race) {

    if(Type_race==2 || Type_race==1) {

        if (control_light) {
            light_clock.restart();
            control_light = false;
        }

        light_time = light_clock.getElapsedTime();

        if (light_time.asSeconds() > 16) {
            song.setTraffic_light(false);
            return true;
        }

        if(control_trafficlight) {
            try {
                if (!T_Light[0].loadFromFile("Semaforo/semaforospento.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[0].setTexture(T_Light[0]);
                S_Light[0].setPosition(sf::Vector2f(500, 300));
                S_Light[0].setOrigin(sf::Vector2f(176, 108));

                if (!T_Light[1].loadFromFile("Semaforo/semaforo1.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[1].setTexture(T_Light[1]);
                S_Light[1].setPosition(sf::Vector2f(500, 300));
                S_Light[1].setOrigin(sf::Vector2f(176, 108));

                if (!T_Light[2].loadFromFile("Semaforo/semaforo2.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[2].setTexture(T_Light[2]);
                S_Light[2].setPosition(sf::Vector2f(500, 300));
                S_Light[2].setOrigin(sf::Vector2f(176, 108));

                if (!T_Light[3].loadFromFile("Semaforo/semaforo3.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[3].setTexture(T_Light[3]);
                S_Light[3].setPosition(sf::Vector2f(500, 300));
                S_Light[3].setOrigin(sf::Vector2f(176, 108));

                if (!T_Light[4].loadFromFile("Semaforo/semaforo4.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[4].setTexture(T_Light[4]);
                S_Light[4].setPosition(sf::Vector2f(500, 300));
                S_Light[4].setOrigin(sf::Vector2f(176, 108));

                if (!T_Light[5].loadFromFile("Semaforo/semaforoacceso.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[5].setTexture(T_Light[5]);
                S_Light[5].setPosition(sf::Vector2f(500, 300));
                S_Light[5].setOrigin(sf::Vector2f(176, 108));

                if (!T_Light[6].loadFromFile("Semaforo/fia.png")) {
                    throw Load_exception("Load_exception:Impossibile caricare file");
                }
                S_Light[6].setTexture(T_Light[6]);
                S_Light[6].setPosition(sf::Vector2f(500, 300));
                S_Light[6].setOrigin(sf::Vector2f(200, 150));

            }

            catch (Load_exception e) {
                window.close();
                error.Check_Image(window);
            }

            if(light_time.asSeconds() > 9)
                song.music_TrafficLight(window, error);
        }

        if (light_time.asSeconds() < 8 )
            window.draw(S_Light[6]);

        if (light_time.asSeconds() > 9 && light_time.asSeconds() < 11)
            window.draw(S_Light[0]);

        if (light_time.asSeconds() > 11 && light_time.asSeconds() < 12)
            window.draw(S_Light[1]);

        if (light_time.asSeconds() > 12 && light_time.asSeconds() < 13)
            window.draw(S_Light[2]);

        if (light_time.asSeconds() > 13 && light_time.asSeconds() < 14)
            window.draw(S_Light[3]);

        if (light_time.asSeconds() > 14 && light_time.asSeconds() < 15)
            window.draw(S_Light[4]);

        if (light_time.asSeconds() > 15 && light_time.asSeconds() < 16)
            window.draw(S_Light[5]);

        return false;
    }
    else return true;
}

void Traffic_Light::setControl_light(bool control_light) {
    Traffic_Light::control_light = control_light;
}
