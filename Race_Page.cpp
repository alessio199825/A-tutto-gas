//
// Created by alessio on 20/03/19.
//

#include "Race_Page.h"
#include "Menu_Game.h"
#include "Load_Exception.h"
#include "Load_Page.h"
#include "Flag_Page.h"

Race_Page::Race_Page(RenderWindow &window, Error &error, int num_circuit, int Race_type, int weath, int lap, int colore_macchina) {
    setWindow(error, window);
    circuitrace=num_circuit;
    Type_race=Race_type;
    meteo=weath;
    giri=lap;
    chooseCar = colore_macchina;
    position=1;
    car= Car(collision);
    cars_cpu=Cars_Cpu(collision);
}

Race_Page::~Race_Page() = default;

void Race_Page::draw(RenderWindow &window) {

    switch (Type_race) {
        case 1:
            traffic_light.setControl_light(false);
            break;
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

        race.setGame(window, circuit, car, error, Type_race, circuitrace, chooseCar);

        car.x_CarPlayer = race.getX_tmp();
        car.y_CarPlayer = race.getY_tmp();
    }

    if (Type_race != 3)
        window.draw(circuit.getS_Pause(0));

    window.draw(circuit.getS_Pause(1));

    if (traffic_light.Light_On(window, error, Type_race)) {

        car.Car_Player_Movement(window, error, circuitrace);

        if (Type_race == 1 || Type_race == 2) {

            car.End_Race(giri, position, circuitrace);
            cars_cpu.getPosition(giri, position);

            cars_cpu.moveCar();

            cars_cpu.drawCpu(window);
        }

        position_car = car.getPos();

        for(int i=0; i<5; i++){
            position_cpu[i] = cars_cpu.getVector_position(i);
        }

        if(position == 7){
            flag = true;
        }

            race.KeyBreak(window, error, song, posx, posy, pageIndex, pageChanged);
            control_setRace = false;

    } else if (Type_race == 2 || Type_race == 1) {

        SaveCircuit();
        cars_cpu.setCircuit(circuitrace);
        cars_cpu.createMachine(window, error);
    }

        weath.setWeather(meteo, window, error);
        song.MusicTime(car, window, error, circuitrace);
        if (Type_race == 2 || Type_race == 1) {
            song.Music_Radio(window, error);
        }

        if (flag) {
            pageIndex = 9;
            pageChanged = true;
            song.stop_Race();
            song.Music_RadioPause(true);
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
            if (!control_setRace && Type_race!=3) {
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
    switch (pageIndex){
        case 0:
            return new Menu_Game(window, error);
        case 9:
            return new Flag_Page(window, error, Type_race, chooseCar, circuitrace, position_car, &position_cpu[0]);
        default:
            return 0;
    }
}

Race_Page::Race_Page() = default;

void Race_Page::SaveCircuit() {

    ofstream f("Control/circuitNum.txt");
    f<<circuitrace<<endl;
    f.close();
}





