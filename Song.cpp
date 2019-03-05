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
                throw "impossibile caricare Texture";
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

void Song::music_Menu(RenderWindow &window, Error &error) {

    if (!menuloop) {
        try {
            if (!music_menu.openFromFile("Music/F1.ogg"))
                throw "impossibile caricare Texture";
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

void Song::stop_Load() {
    music_load.stop();
    loadloop=false;
};


