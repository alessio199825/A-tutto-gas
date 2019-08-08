//
// Created by alessio on 20/03/19.
//

#include "Race_Page.h"
#include "Menu_Game.h"
#include "Load_Exception.h"

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

    if(flag){
        window.draw(S_Flag);
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
        default:
            break;

    }

    switch(circuitrace) {
        case 1:
            if (posx > 910 && posx < 980 && posy > 510 && posy < 580) {

                flag = true;
            }

            break;
        case 2:
            if (posx > 20 && posx < 90 && posy > 510 && posy < 580){

                flag = true;
            }
            break;
        case 3:
            if (posx > 910 && posx < 980 && posy > 120 && posy < 190){

                flag = true;
            }
            break;
        default: break;
    }


    return -1;
}

void Race_Page::setWindow(Error &error, RenderWindow &window) {

    try {
        if (!T_Flag.loadFromFile("race/scacchi.jpg")) {       //pulsante1
            throw Load_exception("Load_exception:Impossibile caricare file");
        }
        S_Flag.setTexture(T_Flag);
    }
    catch(Load_exception e){
        window.close();
        error.Check_Image(window);
    }

}

Menu_State *Race_Page::getNewPage(RenderWindow &window, Error &error) {

    switch (pageIndex){
        case 0:
            return new Menu_Game(window, error);
        default:break;
    }

return 0;

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





