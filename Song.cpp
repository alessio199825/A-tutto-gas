//
// Created by alessio on 05/03/19.
//

#include "Song.h"

Song::Song() {

}

void Song::music_Load(RenderWindow &window, Error &error) {

    if (!loadloop) {
        try {
            if (!music_load.openFromFile("Music/load.ogg")) {
                throw "impossibile caricare Music";
            }
        }
        catch(...){
            window.close();
            error.Check_Sound();
        }
        music_load.play();
    }

    loadloop = true;
}

void Song::stop_Load() {
    music_load.stop();
    loadloop=false;
}

void Song::music_Menu(RenderWindow &window, Error &error) {

    if (!menuloop) {
        try {
            if (!music_menu.openFromFile("Music/F1.ogg"))
                throw "impossibile caricare Music";
        }
        catch(...){
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
                throw "impossibile caricare Music";
        }
        catch(...){
            window.close();
            error.Check_Sound();
        }
        music_race.play();
        if(!traffic_light) {
            music_race.setPlayingOffset(seconds(6.f));
            music_race.setVolume(50.f);
        }
        else
            music_race.setVolume(100.f);
    }
    raceloop = true;
    music_race.setLoop(true);

}

void Song::play_Race() {
    music_race.play();
}

void Song::stop_Race() {
    music_race.stop();
    raceloop = false;
}

void Song::pause_Race() {
    music_race.pause();
    lightloop = true;
};


void Song::music_TrafficLight(RenderWindow &window, Error &error) {
    if (!lightloop) {
        try {
            if (!music_trafficlight.openFromFile("Music/semaforosuono.ogg"))
                throw "impossibile caricare Music";
        }
        catch(...){
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

void Song::music_TeamRadio(RenderWindow &window, Error &error) {
    pause_Race();
    if (!teamradioloop) {
        try {
            if (!music_teamradio[0].openFromFile("Music/teamradio1.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[1].openFromFile("Music/teamradio2.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[2].openFromFile("Music/teamradio3.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[3].openFromFile("Music/teamradio4.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[4].openFromFile("Music/teamradio5.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[5].openFromFile("Music/teamradio6.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[6].openFromFile("Music/teamradio7.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[7].openFromFile("Music/teamradio8.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[8].openFromFile("Music/teamradio9.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[9].openFromFile("Music/teamradio10.ogg"))
                throw "impossibile caricare Music";
            if (!music_teamradio[10].openFromFile("Music/teamradio11.ogg"))
                throw "impossibile caricare Music";
        }
        catch(...){
            window.close();
            error.Check_Sound();
        }

    }
    teamradioloop = true;
}

void Song::music_Box(RenderWindow &window, Error &error) {
    if (!boxloop) {
        try {
            if (!music_box.openFromFile("Music/limitatore.ogg"))
                throw "impossibile caricare Music";
        }
        catch(...){
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
