#include "Time_Trial.h"

Time_Trial::Time_Trial() {

}

bool Time_Trial::setTime_TrialState(Texture *T_timetrial, Sprite *S_timetrial) {
    if (!T_timetrial[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/prova a tempo.jpg")) {
        return true;
    }
    S_timetrial[0].setTexture(T_timetrial[0]);

    if (!T_timetrial[1].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/indietro.jpg")) {       //pulsante1
        return true;
    }
    S_timetrial[1].setTexture(T_timetrial[1]);
    S_timetrial[1].setPosition(sf::Vector2f(25, 25));

    if (!T_timetrial[2].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/seleziona circuito.png")) {       //seleziona circuito
        return true;
    }
    S_timetrial[2].setTexture(T_timetrial[2]);
    S_timetrial[2].setPosition(sf::Vector2f(50, 290));

    if (!T_timetrial[3].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/avanti1.png")) {       //scritta avanti
        return true;
    }
    S_timetrial[3].setTexture(T_timetrial[3]);
    S_timetrial[3].setPosition(sf::Vector2f(600, 25));

    if (!T_timetrial[4].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/circuit2.jpg")) {       //circuito 1
        return true;
    }
    S_timetrial[4].setTexture(T_timetrial[4]);
    S_timetrial[4].setPosition(sf::Vector2f(50, 390));

    if (!T_timetrial[5].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/circuit1-1.jpg")) {       //circuito 2
        return true;
    }
    S_timetrial[5].setTexture(T_timetrial[5]);
    S_timetrial[5].setPosition(sf::Vector2f(350, 390));

    if (!T_timetrial[6].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/circuit3-1.jpg")) {       //circuito 3
         return true;
    }
    S_timetrial[6].setTexture(T_timetrial[6]);
    S_timetrial[6].setPosition(sf::Vector2f(650, 390));
    return false;
}

int Time_Trial::getTime_TrialReturn(double &posx, double &posy) {
    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        return 0;
    }
    return 3;
}

int Time_Trial::getTime_Racecircuit(double &posx, double &posy, Texture *T_timetrial, Sprite *S_timetrial) {

    if (posx > 50 && posx < 310 && posy > 390 && posy < 585) { //tasto circuito 1

        if (!T_timetrial[7].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/circuit2on.jpg")) {       //circuito 1 modificato
            return -1;
        }
        S_timetrial[7].setTexture(T_timetrial[7]);
        S_timetrial[7].setPosition(sf::Vector2f(50, 390));
        circuit = 1;
    }

    if (posx > 350 && posx < 610 && posy > 390 && posy < 585) {     //tasto circuito 2

        if (!T_timetrial[8].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/circuit1on.jpg")) {
            return -1;
        }
        S_timetrial[8].setTexture(T_timetrial[8]);
        S_timetrial[8].setPosition(sf::Vector2f(350, 390));
        circuit = 2;
    }

    if (posx > 650 && posx < 910 && posy > 390 && posy < 585) {     //tasto circuito 3

        if (!T_timetrial[9].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/circuit3on.jpg")) {
            return -1;
        }
        S_timetrial[9].setTexture(T_timetrial[9]);
        S_timetrial[9].setPosition(sf::Vector2f(650, 390));
        circuit = 3;
    }
    return circuit;
}


int Time_Trial::getTime_LoadPage(double &posx, double &posy) {

        if (posx > 600 && posx < 920 && posy > 25 && posy < 115) {             //tasto avanti
        return 1;
    }
    return 0;
}

bool Time_Trial::Timetrial_LoadPage(Texture *T_timetrial, Sprite *S_timetrial) {

    if (!T_timetrial[10].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/planisfero.png")) {       //pulsante1
        return true;
    }
    S_timetrial[10].setTexture(T_timetrial[10]);
    return false;
}

bool Time_Trial::End_TimeTrial(Texture &T_Flag, Sprite &S_Flag) {

    if (!T_Flag.loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/race/scacchi.jpg")) {       //pulsante1
        return true;
    }
    S_Flag.setTexture(T_Flag);
    return false;
}

void Time_Trial::getTime_lap(float x_CarPlayer, float y_CarPlayer) {        //opera del vetto, lo deve finire
                                                                            //memorizza il tempo per time_trial
    switch(circuit) {
        case 1:
            x1_Traguardo = 140;
            x2_Traguardo = 237;
            y1_Traguardo = 300;
            y2_Traguardo = y1_Traguardo;

            if(y1_Traguardo >= y_CarPlayer && x1_Traguardo <= x_CarPlayer && x2_Traguardo >= x_CarPlayer){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                    if(number_of_Lap == i){
                        i++;
                        Lap_Time= new float [number_of_Lap];
                        Lap_Time[number_of_Lap-1]=timelap.asMilliseconds();
                    }
                }
            }
            else{
                control_lap=0;
            }

            break;
        case 2:
            x1_Traguardo = 490;
            x2_Traguardo = x1_Traguardo;
            y1_Traguardo = 28;
            y2_Traguardo = 89;


            if(y1_Traguardo <= y_CarPlayer && y2_Traguardo >= y_CarPlayer && x2_Traguardo <= x_CarPlayer){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                    if(number_of_Lap == i){
                        i++;
                        Lap_Time= new float [number_of_Lap];
                        Lap_Time[number_of_Lap-1]=timelap.asMilliseconds();
                    }
                }
            }
            else{
                control_lap=0;
            }

            break;
        case 3:
            x1_Traguardo = 500;
            x2_Traguardo = x1_Traguardo;
            y1_Traguardo = 486;
            y2_Traguardo = 586;

            if(y1_Traguardo <= y_CarPlayer && y2_Traguardo >= y_CarPlayer && x2_Traguardo >= x_CarPlayer){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                if(number_of_Lap == i){
                    i++;
                    Lap_Time= new float [number_of_Lap];
                    Lap_Time[number_of_Lap-1]=timelap.asMilliseconds();
                }
                }
            }
            else{
                control_lap=0;
            }
            break;
        default:
            break;
    }
}

