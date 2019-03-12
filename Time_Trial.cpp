#include "Time_Trial.h"

Time_Trial::Time_Trial() {

}

void Time_Trial::setTime_TrialState(RenderWindow &window, Error &error) {

    try {
        if (!T_timetrial[0].loadFromFile("Time_Trial/prova a tempo.jpg")) {
            throw "impossibile caricare Texture";
        }
        S_timetrial[0].setTexture(T_timetrial[0]);

        if (!T_timetrial[1].loadFromFile("Time_Trial/indietro.jpg")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_timetrial[1].setTexture(T_timetrial[1]);
        S_timetrial[1].setPosition(sf::Vector2f(25, 25));

        if (!T_timetrial[2].loadFromFile("Time_Trial/seleziona circuito.png")) {       //seleziona circuito
            throw "impossibile caricare Texture";
        }
        S_timetrial[2].setTexture(T_timetrial[2]);
        S_timetrial[2].setPosition(sf::Vector2f(50, 290));

        if (!T_timetrial[3].loadFromFile("Time_Trial/avanti1.png")) {       //scritta avanti
            throw "impossibile caricare Texture";
        }
        S_timetrial[3].setTexture(T_timetrial[3]);
        S_timetrial[3].setPosition(sf::Vector2f(600, 25));

        if (!T_timetrial[4].loadFromFile("Time_Trial/circuit2.jpg")) {       //circuito 1
            throw "impossibile caricare Texture";
        }
        S_timetrial[4].setTexture(T_timetrial[4]);
        S_timetrial[4].setPosition(sf::Vector2f(50, 390));

        if (!T_timetrial[5].loadFromFile("Time_Trial/circuit1-1.jpg")) {       //circuito 2
            throw "impossibile caricare Texture";
        }
        S_timetrial[5].setTexture(T_timetrial[5]);
        S_timetrial[5].setPosition(sf::Vector2f(350, 390));

        if (!T_timetrial[6].loadFromFile("Time_Trial/circuit3-1.jpg")) {       //circuito 3
            throw "impossibile caricare Texture";
        }
        S_timetrial[6].setTexture(T_timetrial[6]);
        S_timetrial[6].setPosition(sf::Vector2f(650, 390));
    }
    catch(...){
        window.close();
        error.Check_Image();
    }

    for (int i = 0; i < 7; i++) {
        window.draw(S_timetrial[i]);
    }

}

int Time_Trial::getReturn(double &posx, double &posy) {

    if (posx > 25 && posx < 125 && posy > 25 && posy < 115) {
        return 0;
    }
    return 3;
}

int Time_Trial::getTime_Racecircuit(double posx, double posy, RenderWindow &window, Error &error) {

    try {
        if (posx > 50 && posx < 310 && posy > 390 && posy < 585) { //tasto circuito 1

            if (!T_timetrial[7].loadFromFile("Time_Trial/circuit2on.jpg")) {       //circuito 1 modificato
                throw "impossibile caricare Texture";
            }
            S_timetrial[7].setTexture(T_timetrial[7]);
            S_timetrial[7].setPosition(sf::Vector2f(50, 390));
            circuit = 1;
        }

        if (posx > 350 && posx < 610 && posy > 390 && posy < 585) {     //tasto circuito 2

            if (!T_timetrial[8].loadFromFile("Time_Trial/circuit1on.jpg")) {
                throw "impossibile caricare Texture";
            }
            S_timetrial[8].setTexture(T_timetrial[8]);
            S_timetrial[8].setPosition(sf::Vector2f(350, 390));
            circuit = 2;
        }

        if (posx > 650 && posx < 910 && posy > 390 && posy < 585) {     //tasto circuito 3

            if (!T_timetrial[9].loadFromFile("Time_Trial/circuit3on.jpg")) {
                throw "impossibile caricare Texture";
            }
            S_timetrial[9].setTexture(T_timetrial[9]);
            S_timetrial[9].setPosition(sf::Vector2f(650, 390));
            circuit = 3;
        }
    }
    catch(...){
        window.close();
        error.Check_Image();
    }

    switch (circuit) {
        case 1:
            window.draw(S_timetrial[7]);
            break;
        case 2:
            window.draw(S_timetrial[8]);
            break;
        case 3:
            window.draw(S_timetrial[9]);
            break;
        default:
            break;
    }
    if(circuit==0)
        circuit=3;
    return circuit;
}


int Time_Trial::getTime_LoadPage(double posx, double posy) {

        if (posx > 600 && posx < 920 && posy > 25 && posy < 115) {
        return 1;
    }
    return 0;
}

void Time_Trial::Timetrial_LoadPage(RenderWindow &window, Error &error) {

    try {
        if (!T_timetrial[10].loadFromFile("Time_Trial/planisfero.png")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_timetrial[10].setTexture(T_timetrial[10]);
    }
    catch(...){
        window.close();
        error.Check_Image();
    }

    window.draw(S_timetrial[10]);

}

void Time_Trial::End_TimeTrial(RenderWindow &window, Error &error) {

    try {
        if (!T_Flag.loadFromFile("race/scacchi.jpg")) {       //pulsante1
            throw "impossibile caricare Texture";
        }
        S_Flag.setTexture(T_Flag);
    }
    catch(...){
        window.close();
        error.Check_Image();
    }

    window.draw(S_Flag);

}

void Time_Trial::getTime_lap(RenderWindow &window) {

    //lettura del circuito scelto
    //definizione della posizione del traguardo e di un passaggio intermedio per il controllo della completezza del giro
    //
    //lettura del tempo impiegato nel completare i vari giri
    // salvataggio dei tempi in array dinamico

    X_tmp=car.getX_CarPlayer();
    Y_tmp=car.getY_CarPlayer();
    switch(circuit) {
        case 1:
            x1_Traguardo = 140;
            x2_Traguardo = 237;
            y1_Traguardo = 300;
            y2_Traguardo = y1_Traguardo;

            if(Y_tmp>=410 && X_tmp>=465 && Y_tmp<=490 && X_tmp<=470){
                intermediate1=intermediate1+1;
                if(intermediate1>number_of_Lap){
                    intermediate1=number_of_Lap;
                }
            }

            if(y1_Traguardo >= Y_tmp && x1_Traguardo <= X_tmp && x2_Traguardo >= X_tmp && intermediate1==number_of_Lap){

                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                    if(number_of_Lap == k){
                        k++;
                      /*  Lap_Time_Minutes = new int [number_of_Lap];
                        Lap_Time_Seconds = new int [number_of_Lap];
                        Lap_Time_Milliseconds = new int [number_of_Lap];*/
                        minute_const = (timelap.asMilliseconds()) / (1000*60);
                        Lap_Time_Minutes[number_of_Lap-1]=minute_const;
                        Lap_Time_Seconds[number_of_Lap-1]= static_cast<int>(timelap.asSeconds() - (Lap_Time_Minutes[number_of_Lap - 1] * 60));
                        Lap_Time_Milliseconds[number_of_Lap-1]=(timelap.asMilliseconds() - (Lap_Time_Seconds[number_of_Lap-1] * 1000));

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

            if(Y_tmp>=430 && X_tmp>=792 && Y_tmp<=440 && X_tmp<=930){
                intermediate2=intermediate2+1;
                if(intermediate2>number_of_Lap){
                    intermediate2=number_of_Lap;
                }
            }

            if(y1_Traguardo <= Y_tmp && y2_Traguardo >= Y_tmp && x2_Traguardo <= X_tmp && intermediate2==number_of_Lap){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                    if(number_of_Lap == k){
                        k++;
                        /*Lap_Time_Minutes = new int [number_of_Lap];
                        Lap_Time_Seconds = new int [number_of_Lap];
                        Lap_Time_Milliseconds = new int [number_of_Lap];*/
                        Lap_Time_Seconds[number_of_Lap-1]= static_cast<int>(timelap.asSeconds() - (minute_const * 60));
                        Lap_Time_Milliseconds[number_of_Lap-1]= static_cast<int>(timelap.asMilliseconds() - (Lap_Time_Seconds[number_of_Lap-1] * 1000));
                        minute_const= static_cast<int>(timelap.asSeconds() / 60);
                        Lap_Time_Minutes[number_of_Lap-1]=minute_const;

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

            if(Y_tmp>=179 && X_tmp>=524 && Y_tmp<=272 && X_tmp<=543){
                intermediate3=intermediate3+1;
                if(intermediate3>number_of_Lap){
                    intermediate3=number_of_Lap;
                }
            }

            if(y1_Traguardo <= Y_tmp && y2_Traguardo >= Y_tmp && x2_Traguardo >= X_tmp && intermediate3==number_of_Lap){
                if(control_lap==0) {
                    number_of_Lap++;
                    control_lap++;
                    timelap= clock_lap.getElapsedTime();
                    clock_lap.restart();

                if(number_of_Lap == k){
                    k++;
                   /* Lap_Time_Minutes = new int [number_of_Lap];
                    Lap_Time_Seconds = new int [number_of_Lap];
                    Lap_Time_Milliseconds = new int [number_of_Lap];*/
                    minute_const= static_cast<int>(timelap.asSeconds() / 60);
                    Lap_Time_Minutes[number_of_Lap-1]=minute_const;
                    Lap_Time_Seconds[number_of_Lap-1]= static_cast<int>(timelap.asSeconds() - (minute_const * 60));
                    Lap_Time_Milliseconds[number_of_Lap-1]= static_cast<int>(timelap.asMilliseconds() - (timelap.asSeconds() * 1000));

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

void Time_Trial::print_TimeLap(RenderWindow &window, Error& error) {

    try {
        if (!F_time.loadFromFile("Font/Open 24 Display St.ttf")) {
            throw "impossibile caricare Texture";
        }
    }
    catch(...){
        window.close();
        error.Check_Image();
    }

    X_time[1].setFont(F_time);
    X_time[1].setCharacterSize(36);
    X_time[1].setFillColor(Color::Red);
    X_time[2].setFont(F_time);
    X_time[2].setCharacterSize(36);
    X_time[2].setFillColor(Color::Red);
    X_time[1].setString(to_string(Lap_Time_Seconds[number_of_Lap-1]));
    X_time[2].setString(to_string(Lap_Time_Milliseconds[number_of_Lap-1]));
    X_time[1].setPosition(450, 300);
    X_time[2].setPosition(500, 300);

    while(number_of_Lap==k-1) {
        window.draw(X_time[1]);
        window.draw(X_time[2]);
    }

}

void Time_Trial::print_TimeMinute(RenderWindow &window, Error &error) {

    try {
        if (!F_time.loadFromFile("Font/Open 24 Display St.ttf")) {
            throw "impossibile caricare Texture";
        }
    }
    catch(...){
        window.close();
        error.Check_Image();
    }

    X_time_minute.setFont(F_time);
    X_time_minute.setCharacterSize(36);
    X_time_minute.setFillColor(Color::Red);
    X_time_minute.setString(to_string(Lap_Time_Minutes[number_of_Lap-1]));
    X_time_minute.setPosition(200, 300);
    window.draw(X_time_minute);

}

