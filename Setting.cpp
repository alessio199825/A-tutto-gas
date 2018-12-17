#include "Setting.h"

Setting::Setting() {

}

bool Setting::setSettingState(Texture *T_setting, Sprite *S_setting) {

    time_returnIn1=C_returnIn.getElapsedTime();
    if (!T_setting[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/impo.jpg")) {
        return true;
    }
    S_setting[0].setTexture(T_setting[0]);

    if (!T_setting[1].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/indietro.jpg")) {       //pulsante1
        return true;
    }
    S_setting[1].setTexture(T_setting[1]);
    S_setting[1].setPosition(sf::Vector2f(25, 25));

    if (!T_setting[2].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/impostazioni.png")) {       //pulsante1
        return true;
    }
    S_setting[2].setTexture(T_setting[2]);
    S_setting[2].setPosition(sf::Vector2f(220, 25));

    if (!T_setting[3].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/istruzioni.png")) {       //pulsante2
        return true;
    }
    S_setting[3].setTexture(T_setting[3]);
    S_setting[3].setPosition(sf::Vector2f(25, 470));

    if (!T_setting[4].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/record.png")) {       //pulsante3
        return true;
    }
    S_setting[4].setTexture(T_setting[4]);
    S_setting[4].setPosition(sf::Vector2f(350, 470));

    if (!T_setting[5].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/riconoscimenti.png")) {       //pulsante4
        return true;
    }
    S_setting[5].setTexture(T_setting[5]);
    S_setting[5].setPosition(sf::Vector2f(675, 470));
    if(time_returnIn1.asSeconds()-time_returnIn.asSeconds()>0.5)
    Instruction_ControlReturn=true;
    return false;
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

bool Setting::setInstruction(Texture *T_setting, Sprite *S_setting) {
    if (!T_setting[6].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/frecce.png")) {
        return true;
    }
    S_setting[6].setTexture(T_setting[6]);

    if (!T_setting[7].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/indietro.jpg")) {       //pulsante1
        return true;
    }
    S_setting[7].setTexture(T_setting[7]);
    S_setting[7].setPosition(sf::Vector2f(25, 25));
    return false;
}

int Setting::get_Instruction_Return(double &posx, double &posy) {

    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        Instruction_ControlReturn=false;
        time_returnIn=C_returnIn.getElapsedTime();
        return 0;
    }
    return 1;
}

int Setting::show_Instruction(Sprite *S_Instruction, Texture *T_Instruction, double *x_position, double *y_position, Clock *C_show) {


    Time_show=C_show->getElapsedTime();
    if (!T_Instruction[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/istru1.png")) {       //pulsante1
        return -1;
    }
    S_Instruction[0].setTexture(T_Instruction[0]);
    S_Instruction[0].setPosition(sf::Vector2f(50, -20));

    if (!T_Instruction[1].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/istru2.png")) {       //pulsante1
        return -1;
    }
    S_Instruction[1].setTexture(T_Instruction[1]);
    S_Instruction[1].setPosition(sf::Vector2f(0, 80));

    if (!T_Instruction[2].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/istru3.png")) {       //pulsante1
        return -1;
    }
    S_Instruction[2].setTexture(T_Instruction[2]);
    S_Instruction[2].setPosition(sf::Vector2f(530, 250));

    if (!T_Instruction[3].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/istru4.png")) {       //pulsante1
        return -1;
    }
    S_Instruction[3].setTexture(T_Instruction[3]);
    S_Instruction[3].setPosition(sf::Vector2f(550, 80));

    if (!T_Instruction[4].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/f1racestars.png")) {       //pulsante1
        return -1;
    }
    S_Instruction[4].setTexture(T_Instruction[4]);
    S_Instruction[4].setPosition(sf::Vector2f(static_cast<float>(*x_position), static_cast<float>(*y_position)));

    if (!T_Instruction[5].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Setting/f1racestars1.png")) {       //pulsante1
        return -1;
    }
    S_Instruction[5].setTexture(T_Instruction[5]);
    S_Instruction[5].setPosition(sf::Vector2f(static_cast<float>(*x_position), static_cast<float>( *y_position)));


    if(Time_show.asSeconds()<6 && Time_show.asSeconds()>1){
        return 0;
    }
    else if(*y_position<=320 && Time_show.asSeconds()>6){
        *y_position=*y_position+8;
    }

    if(Time_show.asSeconds()>8 && Time_show.asSeconds()<14){
        return 2;
    }
    else if(*x_position<=432 && Time_show.asSeconds()>14){
        *x_position=*x_position+20*0.5;
        *y_position=*y_position+20*0.1;
    }

    if(Time_show.asSeconds()>18 && Time_show.asSeconds()<24){
        return 3;
    }
    else if(*x_position<=860 && Time_show.asSeconds()>24){
        *x_position=*x_position+20*0.5;
        *y_position=*y_position-20*0.1;
    }

    if(*x_position>=860){
        return 4;
    }
    else
        return 1;

}

