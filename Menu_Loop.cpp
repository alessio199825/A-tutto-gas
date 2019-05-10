//
// Created by alessio on 19/03/19.
//

#include "Menu_Loop.h"

Menu_Loop::Menu_Loop() {

    window.create(VideoMode(1000,600), "All'ultimo gas");
}

Menu_Loop::~Menu_Loop() = default;

void Menu_Loop::generateWindow(Error &error) {

    State_Option state_option(new LoadMenu_Page(window, error));


    state_option.setWindow(error, window);

    while(window.isOpen()){

        while(window.pollEvent(event)){

            if (event.type == Event::Closed)
                window.close();

            state_option.getActivities(event, window);

            Index = state_option.getActivities(event, window);

        }

        if(state_option.getState()){

            state_option.changeState(window, error);

        }

        if(Index==0){
            song.music_Menu(window, error);
        }
        else{
            song.stop_Menu();
        }

        window.clear();
        state_option.draw(window);
        window.display();
    }

}


