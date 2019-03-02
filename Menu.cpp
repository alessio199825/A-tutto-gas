#include "Menu.h"
#include <iostream>

Menu::Menu() {

    window.create(VideoMode(1000, 600), "All'ultimo gas");         //viene creata la finestra
    sf::Clock C_load;

    Championship champion;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {               //consente la chiusura della finestra
            if (event.type == Event::Closed)
                window.close();
        }


        sf::Time time_load=C_load.getElapsedTime();

        if(time_load.asSeconds()>24 || control_time==2){       //consente di saltare il caricamento dopo 24 secondi oppure dopo aver premuto il tasto tab
            control_time=2;
        }
        else{
            control_time=1;
        }

        window.clear();             //pulisce la finestra

        posx=0;
        posy=0;
        switch(menu_state) {            //consente la scelta della tipologia del menu
            case 0:
                switch (control_time) {
                    case 1:
                        createMenu();                       //crea il menu di caricamento
                        break;
                    case 2:
                        music_load.stop();
                        setMenuState();
                        getChampionship();
                        getSingle_Race();
                        getSetting();
                        getTime_Trial();
                        singleraceon=0;
                        control_timeTrial=0;
                        control_setRace=true;
                        break;
                    default:break;
                }
                break;
            case 1: {

                if (champion.setChampionshipState(window)) {
                    window.close();
                    error.Check_Image();
                }

                posx = getMousePosx();
                posy = getMousePosy();

                menu_state = champion.Return(posx, posy);
                championship_car = champion.getQualifications(posx, posy, window);

                if (championship_car == -1) {
                    window.close();
                    error.Check_Image();
                }

                break;
            }
            case 2:
            {

                switch (singleraceon) {
                    case 0:

                        if (singlerace.setSingle_RaceState(window)) {
                            window.close();
                            error.Check_Image();
                        }

                        posx = getMousePosx();
                        posy = getMousePosy();
                        menu_state = singlerace.getSingle_RaceReturn(posx, posy);
                        Lap = singlerace.getSingle_RaceLap(posx, posy, window);

                        if (Lap == 1) {
                            window.close();
                            error.Check_Image();
                        }

                        meteo = singlerace.getSingle_RaceWeather(posx, posy, window);

                        if (meteo == -1) {
                            window.close();
                            error.Check_Image();
                        }

                        singleraceon = singlerace.getSingle_Raceon(posx, posy);
                        break;
                    case 1:

                        if (singlerace.setSingle_RaceState2(window)) {
                            window.close();
                            error.Check_Image();
                        }

                        posx = getMousePosx();
                        posy = getMousePosy();
                        circuiton = singlerace.getSingle_RaceCircuit(posx, posy, window);

                        if (circuiton == -1) {
                            window.close();
                            error.Check_Image();
                        }

                        singleraceon = singlerace.getSingle_Raceonreturn(posx, posy);

                        if (singleraceon != 0)
                            singleraceon = singlerace.getSingle_LoadPage(posx, posy);
                        x_load = 20;               //fa ripartire da 20 la macchina per il caricamento
                        break;

                    case 2:
                        window_error_singlerace = singlerace.Single_LoadPage(window);

                        if (window_error_singlerace) {
                            window.close();
                            error.Check_Image();
                        }

                        load_machine_error = load_Machine();

                        if (load_machine_error) {
                            window.close();
                            error.Check_Image();
                        }

                        singlerace.Single_LoadPage(window);

                        for (const auto &i : S_loadMachine)
                            window.draw(i);

                        if (Keyboard::isKeyPressed(Keyboard::Key::Tab)) {   //tasto per saltare il caricamento
                            singleraceon = 3;
                        }

                        if (x_load > 800) {
                            control_setRace = true;
                            singleraceon = 3;
                        }
                        break;
                    case 3:
                        if (control_setRace) {
                            window_error_tilemaps = race.setGame(window, circuit, car, cars_cpu, circuiton);
                            car.x_CarPlayer=race.getX_tmp();
                            car.y_CarPlayer=race.getY_tmp();

                            if (window_error_tilemaps) {
                                window.close();
                                error.Check_Image();
                            }
                            control_setRace = false;
                        }

                        window.draw(circuit.getS_tilemaps());
                        window.draw(circuit.getS_Pause(0));
                        window.draw(circuit.getS_Pause(1));
                        car.Car_Player_Movement(window, circuiton);
                        cars_cpu.A_star(window);
                        posx = getMousePosx();
                        posy = getMousePosy();


                        if (race.KeyBreak(posx, posy, menu_state, circuiton, singleraceon)) {
                            window.close();
                            error.Check_Image();
                        }


                        weath.setWeather(meteo, window);
                        break;
                    case 4:
                        if (singlerace.End_SingleRace(window)) {
                            window.close();
                            error.Check_Image();
                        }
                        break;
                    default:
                        break;
                }
                break;

            }
            case 3:
                switch (control_timeTrial) {
                    case 0:
                        window_error_timetrial = timetrial.setTime_TrialState(window);

                        if (window_error_timetrial == 1) {
                            window.close();
                            error.Check_Image();
                        }

                        posx = getMousePosx();
                        posy = getMousePosy();
                        menu_state = timetrial.getReturn(posx, posy);
                        time_circuit = timetrial.getTime_Racecircuit(posx, posy, window);

                        if (time_circuit == -1) {
                            window.close();
                            error.Check_Image();
                        }

                        control_timeTrial=timetrial.getTime_LoadPage(posx, posy);
                        x_load=0;               //fa ripartire da 20 la macchina per il caricamento
                        break;
                    case 1:
                        window_error_Timetrial=timetrial.Timetrial_LoadPage(window);

                        if(window_error_Timetrial) {
                            window.close();
                            error.Check_Image();
                        }

                        if(load_Machine()) {
                            window.close();
                            error.Check_Image();
                        }

                        for (const auto &i : S_loadMachine)
                            window.draw(i);

                        if(Keyboard::isKeyPressed(Keyboard::Key::Tab) )      //tasto per saltare il caricamento
                            control_timeTrial=2;

                        if(x_load>800) {
                            control_setRace = true;
                            control_timeTrial = 2;

                        }
                        break;
                    case 2:
                        music_menu.stop();
                        if(control_setRace) {
                            window_error_tilemaps1 = race.setGame(window, circuit, car, cars_cpu, time_circuit);

                            car.x_CarPlayer=race.getX_tmp();
                            car.y_CarPlayer=race.getY_tmp();

                            if (window_error_tilemaps1) {
                                window.close();
                                error.Check_Image();
                            }
                            control_setRace = false;
                        }

                        window.draw(circuit.getS_tilemaps());
                        window.draw(circuit.getS_Pause(0));
                        window.draw(circuit.getS_Pause(1));
                        car.Car_Player_Movement(window, time_circuit);
                        cars_cpu.A_star(window);
                        posx = getMousePosx();
                        posy = getMousePosy();

                        if(race.KeyBreak(posx, posy, menu_state, time_circuit, control_timeTrial)) {
                            window.close();
                            error.Check_Image();
                        }

                        meteo=1;

                        switch(weath.setWeather(meteo, window)) {
                            case false:
                                weath.do_Sun(window);
                            default:break;
                        }

                        if(timetrial.getTime_lap(window)){
                            window.close();
                            error.Check_Image();
                        }

                        timetrial.getTime_lap(window);
                        timetrial.print_TimeLap(window);
                        timetrial.print_TimeMinute(window);


                        break;
                    case 3:
                        if(timetrial.End_TimeTrial(window)) {
                            window.close();
                            error.Check_Image();
                        }
                        break;
                    default: break;
                }
                break;
            case 4:
                switch(Setting_control) {
                    case 0:
                        if (setting.setSettingState(window)) {
                            window.close();
                            error.Check_Image();
                        }

                        posx = getMousePosx();
                        posy = getMousePosy();
                        menu_state = setting.getSettingPage(posx, posy);
                        Setting_control=setting.getInstructions(posx, posy);

                        if(Setting_control == 1)
                            setting.setControl_C(true);

                        break;
                    case 1:
                        window_error_instruction=setting.setInstruction(window);

                        if (window_error_instruction) {
                            window.close();
                            error.Check_Image();
                        }

                        posx = getMousePosx();
                        posy = getMousePosy();
                        Control_show=setting.show_Instruction();

                        if (Control_show == -1) {
                            window.close();
                            error.Check_Image();
                        }
                        setting.draw_Instruction(window);
                        Setting_control=setting.get_Instruction_Return(posx, posy);
                        break;
                    default:break;
                }
            break;
            default:break;
        }

        window.display();

    }

}

void Menu::createMenu() {

    if (!T_load[0].loadFromFile("Load/loading.jpg")) {
        window.close();
        error.Check_Image();
    }

    S_load[0].setTexture(T_load[0]);

    if (!T_load[1].loadFromFile("Load/caricamento.png")) {
        window.close();
        error.Check_Image();
    }

    S_load[1].setTexture(T_load[1]);

    S_load[1].setTexture(T_load[1]);
    S_load[1].setPosition(sf::Vector2f(240, 350));
    S_load[1].setOrigin(sf::Vector2f(50, 50));
    S_load[1].setRotation(degree_load);
    degree_load=degree_load+25;

    if (!music_menuloop) {              //musica menu
        if (!music_menu.openFromFile("Menu/F1.ogg")) {
            window.close();
            error.Check_Sound();
        }
    }
    music_menu.play();
    music_menuloop = true;
    music_menu.setLoop(true);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab) ) {      //tasto per saltare il caricamento
        control_time=2;
    }

    window.draw(S_load[0]);
    window.draw(S_load[1]);

}

int Menu::setMenuState() {

    if (!T_menu[0].loadFromFile("Menu/2307.jpg")) {
        window.close();
        error.Check_Image();
    }

    S_menu[0].setTexture(T_menu[0]);

    if (!T_menu[1].loadFromFile("Menu/titolo.png")) {       //titolo
        window.close();
        error.Check_Image();
    }
    S_menu[1].setTexture(T_menu[1]);
    S_menu[1].setPosition(sf::Vector2f(220, 25));

    if (!T_menu[2].loadFromFile("Menu/carriera.png")) {       //pulsante1
        window.close();
        error.Check_Image();
    }
    S_menu[2].setTexture(T_menu[2]);
    S_menu[2].setPosition(sf::Vector2f(650, 170));

    if (!T_menu[3].loadFromFile("Menu/gara singola.png")) {       //pulsante 2
        window.close();
        error.Check_Image();
    }
    S_menu[3].setTexture(T_menu[3]);
    S_menu[3].setPosition(sf::Vector2f(650, 270));

    if (!T_menu[4].loadFromFile("Menu/prova a tempo.png")) {      //pulsante 3
        window.close();
        error.Check_Image();
    }
    S_menu[4].setTexture(T_menu[4]);
    S_menu[4].setPosition(sf::Vector2f(650, 370));

    if (!T_menu[5].loadFromFile("Menu/impostazioni.png")) {       //pulsante 4
        window.close();
        error.Check_Image();
    }
    S_menu[5].setTexture(T_menu[5]);
    S_menu[5].setPosition(sf::Vector2f(650, 470));

    if (!music_loadloop) {      //musica menu
        if (!music_load.openFromFile("Load/load.ogg")) {
            window.close();
            error.Check_Sound();
            return -1;
        }
    }

        music_load.play();
        music_loadloop = true;


    window.draw(S_menu[0]);
    window.draw(S_menu[1]);
    window.draw(S_menu[2]);
    window.draw(S_menu[3]);
    window.draw(S_menu[4]);
    window.draw(S_menu[5]);

    return 0;
}

int Menu::getChampionship() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {      //tasto carriera

        if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 970 &&
            Mouse::getPosition(window).y > 170 && Mouse::getPosition(window).y < 240) {
            menu_state=1;
        }
    }
    return 0;
}

int Menu::getSingle_Race() {
    if(Mouse::isButtonPressed(Mouse::Left) ) {      //tasto gara singola

        if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 970 &&
            Mouse::getPosition(window).y > 270 && Mouse::getPosition(window).y < 340) {
            menu_state=2;
        }
    }
    return 0;
}

int Menu::getSetting() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {      //prova a tempo

        if (Mouse::getPosition(window).x > 625 && Mouse::getPosition(window).x < 970 &&
            Mouse::getPosition(window).y > 370 && Mouse::getPosition(window).y < 440) {
            menu_state=3;

        }
    }
    return 0;
}

int Menu::getTime_Trial() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {      //tasto impostazioni

        if (Mouse::getPosition(window).x > 650 && Mouse::getPosition(window).x < 970 &&
            Mouse::getPosition(window).y > 470 && Mouse::getPosition(window).y < 540) {
            menu_state=4;
        }
    }
    return 0;
}

double Menu::getMousePosx() {

    if(Mouse::isButtonPressed(Mouse::Left) ) {
        posx=Mouse::getPosition(window).x;
    }
    return posx;
}

double Menu::getMousePosy() {
    if(Mouse::isButtonPressed(Mouse::Left) ) {
        posy = Mouse::getPosition(window).y;
    }
    return posy;
}

bool Menu::load_Machine() {
    if(!T_loadMachine[0].loadFromFile("Load/fone.png"))
    {
        return true;
    }
    S_loadMachine[0].setTexture(T_loadMachine[0]);
    S_loadMachine[0].setPosition(Vector2f(x_load,387));

    if(!T_loadMachine[1].loadFromFile("Load/ruotona.png"))
    {
        return true;
    }
    S_loadMachine[1].setTexture(T_loadMachine[1]);
    S_loadMachine[1].setPosition(Vector2f(x_load+22,462));

    S_loadMachine[1].setOrigin(13,13);
    S_loadMachine[1].setRotation(load_degree);

    if(!T_loadMachine[2].loadFromFile("Load/ruotona.png"))
    {
        return true;
    }
    S_loadMachine[2].setTexture(T_loadMachine[2]);
    S_loadMachine[2].setPosition(Vector2f(x_load+144,462));

    S_loadMachine[2].setOrigin(13,13);
    S_loadMachine[2].setRotation(load_degree);

    x_load=x_load+8;
    load_degree=load_degree+35;

    return false;
}




