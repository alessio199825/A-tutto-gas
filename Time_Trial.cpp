#include "Time_Trial.h"

Time_Trial::Time_Trial() {

}

bool Time_Trial::setTime_TrialState(Texture *T_timetrial, Sprite *S_timetrial) {

    //caricamento delle immagini relative alla pagina della prova a tempo
    //
    //tutto è andato a buon fine se la funzione ritorna false
    //se la funzione ritorna true si apre il pop-up di errore

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

int Time_Trial::getReturn(double &posx, double &posy) {

    //definizione della posizione del tasto indietro per tornare all pagina iniziale

    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        return 0;
    }
    return 3;
}

int Time_Trial::getTime_Racecircuit(double &posx, double &posy, Texture *T_timetrial, Sprite *S_timetrial) {

    //creazione dei tasti per la scelta del circuito sul quale disputare la prova a tempo
    //
    //la funzione ritorna 1, 2, 3 a seconda del circuito scelto
    //se la funzione dovesse ritornare -1 significa che il caricamento delle immagini non è andato a buon fine

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

        //definizione della posizione del tasto avanti per passare al caricamento della modalità

        if (posx > 600 && posx < 920 && posy > 25 && posy < 115) {
        return 1;
    }
    return 0;
}

bool Time_Trial::Timetrial_LoadPage(Texture *T_timetrial, Sprite *S_timetrial) {

    //caricamento della pagina di transizione precedente al caricamentop finale della determinata modalità di gioco
    //
    //se la funzione dovesse ritornare -1 significa che il caricamento delle immagini non è andato a buon fine

    if (!T_timetrial[10].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Time_Trial/planisfero.png")) {       //pulsante1
        return true;
    }
    S_timetrial[10].setTexture(T_timetrial[10]);
    return false;
}

bool Time_Trial::End_TimeTrial(Texture &T_Flag, Sprite &S_Flag) {

    //caricamento della bandiera a scacchi come fase di transizione dopo aver terminato la prova a tempo
    //
    //se la funzione dovesse ritornare -1 significa che il caricamento delle immagini non è andato a buon fine

    if (!T_Flag.loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/race/scacchi.jpg")) {       //pulsante1
        return true;
    }
    S_Flag.setTexture(T_Flag);
    return false;
}

void Time_Trial::getTime_lap(float x_CarPlayer, float y_CarPlayer) {

    //lettura del circuito scelto
    //definizione della posizione del traguardo e di un passaggio intermedio per il controllo della completezza del giro
    //
    //lettura del tempo impiegato nel completare i vari giri
    // salvataggio dei tempi in array dinamico

    switch(circuit) {
        case 1:
            x1_Traguardo = 140;
            x2_Traguardo = 237;
            y1_Traguardo = 300;
            y2_Traguardo = y1_Traguardo;

            if(y_CarPlayer>=410 && x_CarPlayer>=465 && y_CarPlayer<=490 && x_CarPlayer<=470){
                intermediate1=intermediate1+1;
                if(intermediate1>number_of_Lap){
                    intermediate1=number_of_Lap;
                }
            }

            if(y1_Traguardo >= y_CarPlayer && x1_Traguardo <= x_CarPlayer && x2_Traguardo >= x_CarPlayer && intermediate1==number_of_Lap){

                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                    if(number_of_Lap == i){
                        i++;
                        Lap_Time_Minutes = new int [number_of_Lap];
                        Lap_Time_Seconds = new int [number_of_Lap];
                        minute_const= static_cast<int>(timelap.asSeconds() / 60);
                        Lap_Time_Minutes[number_of_Lap-1]=minute_const;
                        Lap_Time_Seconds[number_of_Lap-1]= static_cast<int>(timelap.asSeconds() - minute_const * 60);
                        Lap_Time_Milliseconds[number_of_Lap-1]= static_cast<int>(timelap.asMilliseconds() - timelap.asSeconds() * 1000);
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

            if(y_CarPlayer>=430 && x_CarPlayer>=792 && y_CarPlayer<=440 && x_CarPlayer<=930){
                intermediate2=intermediate2+1;
                if(intermediate2>number_of_Lap){
                    intermediate2=number_of_Lap;
                }
            }

            if(y1_Traguardo <= y_CarPlayer && y2_Traguardo >= y_CarPlayer && x2_Traguardo <= x_CarPlayer && intermediate2==number_of_Lap){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                    if(number_of_Lap == i){
                        i++;
                        Lap_Time_Minutes = new int [number_of_Lap];
                        Lap_Time_Seconds = new int [number_of_Lap];
                        minute_const= static_cast<int>(timelap.asSeconds() / 60);
                        Lap_Time_Minutes[number_of_Lap-1]=minute_const;
                        Lap_Time_Seconds[number_of_Lap-1]= static_cast<int>(timelap.asSeconds() - minute_const * 60);
                        Lap_Time_Milliseconds[number_of_Lap-1]= static_cast<int>(timelap.asMilliseconds() - timelap.asSeconds() * 1000);
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

            if(y_CarPlayer>=179 && x_CarPlayer>=524 && y_CarPlayer<=272 && x_CarPlayer<=543){
                intermediate3=intermediate3+1;
                if(intermediate3>number_of_Lap){
                    intermediate3=number_of_Lap;
                }
            }

            if(y1_Traguardo <= y_CarPlayer && y2_Traguardo >= y_CarPlayer && x2_Traguardo >= x_CarPlayer && intermediate3==number_of_Lap){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                if(number_of_Lap == i){
                    i++;
                    Lap_Time_Minutes = new int [number_of_Lap];
                    Lap_Time_Seconds = new int [number_of_Lap];
                    minute_const= static_cast<int>(timelap.asSeconds() / 60);
                    Lap_Time_Minutes[number_of_Lap-1]=minute_const;
                    Lap_Time_Seconds[number_of_Lap-1]= static_cast<int>(timelap.asSeconds() - minute_const * 60);
                    Lap_Time_Milliseconds[number_of_Lap-1]= static_cast<int>(timelap.asMilliseconds() - timelap.asSeconds() * 1000);
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

