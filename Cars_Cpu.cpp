//
// Created by alessio on 18/12/18.
//

#include "Cars_Cpu.h"

Cars_Cpu::Cars_Cpu() {

}

bool Cars_Cpu::createMachine(Texture *T_CpuCar, Sprite *S_CpuCar, float *x_cpu, float *y_cpu) {

    if (!T_CpuCar[0].loadFromFile("/home/alessio/Scrivania/Progetto Esame Programmazione/All_ultimo gas/Cars_Cpu/macchina4_trasparenza.png")) {
        return true;
    }

    S_CpuCar[0].setTexture(T_CpuCar[0]);
    S_CpuCar[0].setOrigin(9.5, 0);
    S_CpuCar[0].setPosition(Vector2f(*x_cpu, *y_cpu));

    return false;
}

void Cars_Cpu::A_star(float *x_cpu, float *y_cpu, Sprite *S_CpuCar) {

    if(*y_cpu<600 && *x_cpu >10 && *y_cpu >0 && *x_cpu<1000){
        *y_cpu=*y_cpu-0.1;
    }

    S_CpuCar[0].setPosition(Vector2f(*x_cpu, *y_cpu));
}
