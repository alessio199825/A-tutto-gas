//
// Created by alessio on 18/12/18.
//

#include "Cars_Cpu.h"

Cars_Cpu::Cars_Cpu() {

}

void Cars_Cpu::createMachine(RenderWindow &window, Error &error) {

    try {
        if (!T_CpuCar[0].loadFromFile("Cars_Cpu/macchina4_trasparenza.png")) {
            throw "impossibile caricare Texture";
        }
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }

    S_CpuCar[0].setTexture(T_CpuCar[0]);
    S_CpuCar[0].setOrigin(9.5, 0);
    S_CpuCar[0].setPosition(Vector2f(x_cpu, y_cpu));
    for(int i=0; i<1; i++)
        window.draw(S_CpuCar[i]);

}

void Cars_Cpu::A_star(RenderWindow &window) {

    if(y_cpu<600 && x_cpu >10 && y_cpu >0 && x_cpu<1000){
        y_cpu=y_cpu-0.1;
    }

    S_CpuCar[0].setPosition(Vector2f(x_cpu, y_cpu));
    for(int i=0; i<1; i++)
        window.draw(S_CpuCar[i]);
}

