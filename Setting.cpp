#include "Setting.h"

Setting::Setting() {

}

void Setting::setSettingState(RenderWindow &window, Error &error) {

    try {
        time_returnIn1 = C_returnIn.getElapsedTime();
        if (!T_setting[0].loadFromFile("Setting/impo.jpg")) {
            throw "impossibile caricare Texture";
        }
        S_setting[0].setTexture(T_setting[0]);

        if (!T_setting[1].loadFromFile("Setting/indietro.jpg")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_setting[1].setTexture(T_setting[1]);
        S_setting[1].setPosition(sf::Vector2f(25, 25));

        if (!T_setting[2].loadFromFile("Setting/impostazioni.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_setting[2].setTexture(T_setting[2]);
        S_setting[2].setPosition(sf::Vector2f(220, 25));

        if (!T_setting[3].loadFromFile("Setting/istruzioni.png")) {       //pulsante2
            throw "impossibile caricare Texture";
        }
        S_setting[3].setTexture(T_setting[3]);
        S_setting[3].setPosition(sf::Vector2f(25, 470));

        if (!T_setting[4].loadFromFile("Setting/record.png")) {       //pulsante3
            throw "impossibile caricare Texture";
        }
        S_setting[4].setTexture(T_setting[4]);
        S_setting[4].setPosition(sf::Vector2f(350, 470));

        if (!T_setting[5].loadFromFile("Setting/riconoscimenti.png")) {       //pulsante4
            throw "impossibile caricare Texture";
        }
        S_setting[5].setTexture(T_setting[5]);
        S_setting[5].setPosition(sf::Vector2f(675, 470));
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }

    if(time_returnIn1.asSeconds()-time_returnIn.asSeconds()>0.5)
    Instruction_ControlReturn=true;

    for(int i=0; i<6; i++)
    window.draw(S_setting[i]);

}

int Setting::getSettingPage(double &posx, double &posy) {       //tasto indietro
    if (posx > 25 && posx < 125 && posy > 25 && posy < 115 && Instruction_ControlReturn) {
        return 0;
    }
    return 4;
}

int Setting::getInstructions(double &posx, double &posy) {

        if (posx > 25 && posx < 325 && posy > 470 && posy < 540) {
            return 1;
        }
    return 0;
}

void Setting::setInstruction(RenderWindow &window, Error &error) {

    try {
        if (!T_setting[6].loadFromFile("Setting/frecce.png")) {
            throw "impossibile caricare Texture";
        }
        S_setting[6].setTexture(T_setting[6]);

        if (!T_setting[7].loadFromFile("Setting/indietro.jpg")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_setting[7].setTexture(T_setting[7]);
        S_setting[7].setPosition(sf::Vector2f(25, 25));
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }

    window.draw(S_setting[6]);
    window.draw(S_setting[7]);

}

int Setting::get_Instruction_Return(double &posx, double &posy) {

    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        Instruction_ControlReturn=false;
        time_returnIn=C_returnIn.getElapsedTime();
        return 0;
    }
    return 1;
}

int Setting::show_Instruction(RenderWindow &window, Error &error) {

    if(control_C) {
        C_show.restart();
        x_position=0;
        y_position=150;
        control_C = false;
    }
    Time_show=C_show.getElapsedTime();
    try {
        if (!T_Instruction[0].loadFromFile("Setting/istru1.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Instruction[0].setTexture(T_Instruction[0]);
        S_Instruction[0].setPosition(sf::Vector2f(50, -20));

        if (!T_Instruction[1].loadFromFile("Setting/istru2.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Instruction[1].setTexture(T_Instruction[1]);
        S_Instruction[1].setPosition(sf::Vector2f(0, 80));

        if (!T_Instruction[2].loadFromFile("Setting/istru3.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Instruction[2].setTexture(T_Instruction[2]);
        S_Instruction[2].setPosition(sf::Vector2f(530, 250));

        if (!T_Instruction[3].loadFromFile("Setting/istru4.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Instruction[3].setTexture(T_Instruction[3]);
        S_Instruction[3].setPosition(sf::Vector2f(550, 80));

        if (!T_Instruction[4].loadFromFile("Setting/f1racestars.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Instruction[4].setTexture(T_Instruction[4]);
        S_Instruction[4].setPosition(sf::Vector2f(static_cast<float>(x_position), static_cast<float>(y_position)));

        if (!T_Instruction[5].loadFromFile("Setting/f1racestars1.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Instruction[5].setTexture(T_Instruction[5]);
        S_Instruction[5].setPosition(sf::Vector2f(static_cast<float>(x_position), static_cast<float>( y_position)));
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }

    if(Time_show.asSeconds()<6 && Time_show.asSeconds()>1){
        ControlShow=0;
        return 0;
    }
    else if(y_position<=320 && Time_show.asSeconds()>6){
        y_position=y_position+15;
    }

    if(Time_show.asSeconds()>10 && Time_show.asSeconds()<14){
        ControlShow=2;
        return 2;
    }
    else if(x_position<=432 && Time_show.asSeconds()>14){
        x_position=x_position+40*0.5;
        y_position=y_position+40*0.1;
    }

    if(Time_show.asSeconds()>20 && Time_show.asSeconds()<24){
        ControlShow=3;
        return 3;
    }
    else if(x_position<=860 && Time_show.asSeconds()>24){
        x_position=x_position+40*0.5;
        y_position=y_position-40*0.1;
    }

    if(x_position>=860){
        ControlShow=4;
        return 4;
    }
    else {
        ControlShow = 1;
        return 1;
    }

}


void Setting::draw_Instruction(RenderWindow &window) {

    switch (ControlShow){
        case 0:
            window.draw(S_Instruction[0]);
            window.draw(S_Instruction[4]);
            break;
        case 1:
            window.draw(S_Instruction[4]);
            break;
        case 2:
            window.draw(S_Instruction[1]);
            window.draw(S_Instruction[4]);
            break;
        case 3:
            window.draw(S_Instruction[2]);
            window.draw(S_Instruction[4]);
            break;
        case 4:
            window.draw(S_Instruction[3]);
            window.draw(S_Instruction[5]);
        default: break;
    }

}

void Setting::setControl_C(bool control_C) {
    Setting::control_C = control_C;
}




