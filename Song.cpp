//
// Created by alessio on 05/03/19.
//

#include "Song.h"
#include "Load_Exception.h"

Song::Song() = default;

void Song::music_Load(RenderWindow &window, Error &error) {

    if (!loadloop) {
        try {
            if (!music_load.openFromFile("Music/load.ogg")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }
        }
        catch(Load_exception e){
            window.close();
            error.Check_Sound();
        }
        music_load.play();
    }

    loadloop = true;
}

void Song::music_Menu(RenderWindow &window, Error &error) {

    if (!menuloop) {
        try {
            if (!music_menu.openFromFile("Music/F1.ogg"))
                throw Load_exception("Load_exception:Impossibile caricare file");
        }
        catch(Load_exception e){
            window.close();
            error.Check_Sound();
        }
        music_menu.play();
    }

    menuloop = true;
    music_menu.setLoop(true);
}

void Song::stop_Menu() {
    music_menu.stop();
    menuloop=false;
}

void Song::music_Race(RenderWindow &window, Error &error) {
    if (!raceloop) {
        try {
            if (!music_race.openFromFile("Music/musicagara1.ogg"))
                throw Load_exception("Load_exception:Impossibile caricare file");
        }
        catch(Load_exception e){
            window.close();
            error.Check_Sound();
        }
        music_race.play();
        if(traffic_light) {
            music_race.setPlayingOffset(seconds(6.f));
        }
    }
    raceloop = true;
    music_race.setLoop(true);

}

void Song::stop_Race() {
    music_race.stop();
    raceloop = false;
}

void Song::pause_Race(bool Select_Pause) {
    if(Select_Pause)
        music_race.pause();
    if(!Select_Pause)
        music_race.play();
}


void Song::music_TrafficLight(RenderWindow &window, Error &error) {
    if (!lightloop) {
        try {
            if (!music_trafficlight.openFromFile("Music/semaforosuono.ogg"))
                throw Load_exception("Load_exception:Impossibile caricare file");
        }
        catch(Load_exception e){
            window.close();
            error.Check_Sound();
        }
        traffic_light=true;
        music_trafficlight.play();
    }
    lightloop = true;
}

void Song::setLightloop(bool lightloop) {
    Song::lightloop = lightloop;
}


void Song::music_Box(RenderWindow &window, Error &error) {
    if (!boxloop) {
        try {
            if (!music_box.openFromFile("Music/limitatore.ogg"))
                throw Load_exception("Load_exception:Impossibile caricare file");
        }
        catch(Load_exception e){
            window.close();
            error.Check_Sound();
        }
        music_box.play();
    }
    music_box.setLoop(true);
    boxloop = true;
}

void Song::MusicTime(Car &car, RenderWindow &window, Error &error, int num_circuit) {
    switch(num_circuit){
        case 1:
            if(car.getX_CarPlayer()<137 && car.getY_CarPlayer()>231 && car.getY_CarPlayer()<517) {
                stop_Race();
                music_Box(window, error);
            }
            else {
                if(boxloop)
                    stop_Box();
                music_Race(window, error);
            }
            break;
        case 2:
            if(car.getX_CarPlayer()>90 && car.getX_CarPlayer()<724 && car.getY_CarPlayer()<27) {
                stop_Race();
                music_Box(window, error);
            }
            else{
                if(boxloop)
                    stop_Box();
                music_Race(window, error);

            }
            break;
        case 3:
            if(car.getX_CarPlayer()<870 && car.getX_CarPlayer()>687 && car.getY_CarPlayer()>373 && car.getY_CarPlayer()<475) {
                stop_Race();
                music_Box(window, error);
            }
            else{
                if(boxloop)
                    stop_Box();
                music_Race(window, error);
            }
            break;
        default: break;
    }
}

void Song::stop_Box() {
    music_box.stop();
    boxloop = false;
}

void Song::setTraffic_light(bool traffic_light) {
    Song::traffic_light = traffic_light;
}

void Song::Music_Radio(RenderWindow &window, Error &error) {

    srand(static_cast<unsigned int>(time(NULL)));                  //potrebbe essere utile richiamarlo solo una volta e inibirne il funzionamento
    timeRadio = clockRadio.getElapsedTime();
    if (timeRadio.asSeconds() > 15) {
        SelectRadio = (rand() % 19) + 1;
        try {

            if (SelectRadio <= 9) {
                switch (SelectRadio % 3) {
                    case 0:
                        if (!M_teamRadio.openFromFile("Music/teamradio9.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 4.50;
                        break;
                    case 1:
                        if (!M_teamRadio.openFromFile("Music/teamradio2.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 4;
                        break;
                    case 2:
                        if (!M_teamRadio.openFromFile("Music/teamradio11.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 3.50;
                        break;
                    default:
                        break;
                }
            }
            if (SelectRadio > 9 || SelectRadio <= 17) {
                switch (SelectRadio / 2) {
                    case 5:
                        if (!M_teamRadio.openFromFile("Music/teamradio1.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 5.50;
                        break;
                    case 6:
                        if (!M_teamRadio.openFromFile("Music/teamradio5.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 3.50;
                        break;
                    case 7:
                        if (!M_teamRadio.openFromFile("Music/teamradio6.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 5;
                        break;
                    case 8:
                        if (!M_teamRadio.openFromFile("Music/teamradio7.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 7;
                        break;
                    default:
                        break;
                }
            }
            if (SelectRadio > 17) {
                switch (SelectRadio % 2) {
                    case 0:
                        if (!M_teamRadio.openFromFile("Music/teamradio3.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 11;
                        break;
                    case 1:
                        if (!M_teamRadio.openFromFile("Music/teamradio8.ogg"))
                            throw Load_exception("Load_exception:Impossibile caricare file");
                        Radio_Seconds = 9.50;
                        break;
                }
            }
        }
        catch (Load_exception e) {
            window.close();
            error.Check_Sound();
        }
        clockRadio.restart();
        timeRadio = clockRadio.getElapsedTime();
        pause_Race(true);
        M_teamRadio.play();
    }

    if (timeRadio.asSeconds() > Radio_Seconds) {
        pause_Race(false);
        Radio_Seconds=20;
    }

}

void Song::Music_RadioPause(bool controlRadio) {
    if(controlRadio)
        M_teamRadio.pause();
    if(!controlRadio)
        M_teamRadio.play();
}

