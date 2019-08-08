//
// Created by alessio on 20/03/19.
//

#include "Race_Page.h"
#include "Menu_Game.h"
#include "Load_Exception.h"
#include "Load_Page.h"
#include "Flag_Page.h"

Race_Page::Race_Page(RenderWindow &window, Error &error, int num_circuit, int Race_type, int weath, int lap) {
    setWindow(error, window);
    circuitrace=num_circuit;
    Type_race=Race_type;
    meteo=weath;
    giri=lap;
}

Race_Page::~Race_Page() = default;

void Race_Page::draw(RenderWindow &window) {

    switch(Type_race) {
        case 2:
            traffic_light.setControl_light(false);
            break;
        case 3:
            traffic_light.setControl_light(true);
            break;
        default:
            break;
    }


    window.draw(circuit.getS_tilemaps());

    if (control_setRace) {

        race.setGame(window, circuit, car, error, Type_race, circuitrace);

        car.x_CarPlayer=race.getX_tmp();
        car.y_CarPlayer=race.getY_tmp();
    }

    window.draw(circuit.getS_Pause(0));
    window.draw(circuit.getS_Pause(1));

    if(traffic_light.Light_On(window, error, Type_race)) {

        car.Car_Player_Movement(window, error, circuitrace);

        posx = getMousePosX(window);
        posy = getMousePosY(window);

        if(Type_race==2) {
            
            flag = car.End_Race(giri);
            
            cars_cpu.moveCar();
            cars_cpu.drawCpu(window);

        }

        race.KeyBreak(window, error, song, posx, posy, pageIndex, pageChanged, circuitrace);
        control_setRace = false;

    }
    else if(Type_race==2) {
        SaveCircuit();
        cars_cpu.setCircuit(circuitrace);
        cars_cpu.createMachine(window, error);
    }

    weath.setWeather(meteo, window, error);
    song.MusicTime(car, window, error, circuitrace);
    if(Type_race==2){
        song.Music_Radio(window, error);
    }

}

int Race_Page::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {
        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Escape:                      //con il tasto esc viene chiuso il programma
                song.stop_Race();
                window.close();
                    break;
                default:
                    break;
            }
            break;

        case Event::MouseButtonReleased:
            if (!control_setRace) {
                switch (circuitrace) {
                    case 1:
                        if (Mouse::getPosition(window).x > 910 && Mouse::getPosition(window).x < 980 &&
                            Mouse::getPosition(window).y > 510 && Mouse::getPosition(window).y < 580) {
                            pageIndex = 9;
                            pageChanged = true;
                            song.stop_Race();
                            song.Music_RadioPause(true);
                        }
                        break;
                    case 2:
                        if (Mouse::getPosition(window).x > 20 && Mouse::getPosition(window).x < 90 &&
                            Mouse::getPosition(window).y > 510 && Mouse::getPosition(window).y < 580) {
                            pageIndex = 9;
                            pageChanged = true;
                            song.stop_Race();
                            song.Music_RadioPause(true);
                        }
                        break;
                    case 3:
                        if (Mouse::getPosition(window).x > 910 && Mouse::getPosition(window).x < 980 &&
                            Mouse::getPosition(window).y > 120 && Mouse::getPosition(window).y < 190) {
                            pageIndex = 9;
                            pageChanged = true;
                            song.stop_Race();
                            song.Music_RadioPause(true);
                        }
                        break;
                    default:
                        break;
                }
            }

        default:
            break;
    }

    return -1;
}

void Race_Page::setWindow(Error &error, RenderWindow &window) {



}

Menu_State *Race_Page::getNewPage(RenderWindow &window, Error &error) {
    cout<<pageIndex<<endl;
    switch (pageIndex){
        case 0:
            return new Menu_Game(window, error);
        case 9:
            return new Flag_Page(window, error, circuitrace, Type_race);
        default:
            return 0;
    }
}

double Race_Page::getMousePosX(RenderWindow &window) {
    if(Mouse::isButtonPressed(Mouse::Left) ) {
        posx=Mouse::getPosition(window).x;
    }
    return posx;
}

double Race_Page::getMousePosY(RenderWindow &window) {
    if(Mouse::isButtonPressed(Mouse::Left) ) {
        posy = Mouse::getPosition(window).y;
    }
    return posy;
}

Race_Page::Race_Page() = default;

void Race_Page::SaveCircuit() {

    ofstream f("Control/circuitNum.txt");
    f<<circuitrace<<endl;
    f.close();
}





