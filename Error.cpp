#include "Error.h"

Error::Error()
{

}

void Error::Check_Image(Texture *T_Error, Sprite *S_Error) {

    window_error.create(VideoMode(500, 300), "Errore"); //creazione di un pop-up che avverte di un problema nel caricamento di un immagine
    while (window_error.isOpen()) {
        while (window_error.pollEvent(
                event_error)) {               //consente la chiusura della finestra e di tutto il gioco
            if (event_error.type == Event::Closed)
                window_error.close();
        }

        T_Error[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Error/warning.jpg");
        S_Error[0].setTexture(T_Error[0]);

        window_error.clear();
        window_error.draw(S_Error[0]);
        window_error.display();
    }
}

void Error::Check_Sound(Texture *T_Error, Sprite *S_Error) {    //ricordarsi di cambiare l'immagine, è la stessa dell'image error

    window_error.create(VideoMode(500, 300), "Errore");     //creazione di un pop-up che avverte di un problema nel caricamento di un suono
    while (window_error.isOpen()) {
        while (window_error.pollEvent(
                event_error)) {               //consente la chiusura della finestra e di tutto il gioco
            if (event_error.type == Event::Closed)
                window_error.close();
        }

        T_Error[1].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Error/warning1.jpg");
        S_Error[1].setTexture(T_Error[1]);

        window_error.clear();
        window_error.draw(S_Error[1]);
        window_error.display();
    }
}