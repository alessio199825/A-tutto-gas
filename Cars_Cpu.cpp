//
// Created by alessio on 18/12/18.
//

#include "Cars_Cpu.h"

Cars_Cpu::Cars_Cpu() {

}

void Cars_Cpu::createMachine(RenderWindow &window, Error &error) {

    if(i==0) {
        try {
            if (!T_CpuCar[0].loadFromFile("Cars_Cpu/macchina4_trasparenza.png")) {
                throw "impossibile caricare Texture";
            }
        }
        catch (...) {
            window.close();
            error.Check_Image(window);
        }
        i++;
    }

    S_CpuCar[0].setTexture(T_CpuCar[0]);
    S_CpuCar[0].setOrigin(9.5, 0);
    S_CpuCar[0].setRotation(180);

    S_CpuCar[0].setPosition(Vector2f(x_cpu, y_cpu));
    for(int i=0; i<1; i++)
        window.draw(S_CpuCar[i]);

}

void Cars_Cpu::moveCar(int x, int y) {        //gestire bene setCar e move Car che forse fanno la stessa cosa

    x_cpu=x;
    y_cpu=y;
    S_CpuCar[0].setPosition(x_cpu,y_cpu);

}

float Cars_Cpu::getX_cpu() const {
    return x_cpu;
}

float Cars_Cpu::getY_cpu() const {
    return y_cpu;
}

void Cars_Cpu::setPos() {

    //cout<<index<<endl;
    //cout<<posCar.size()<<endl;

    if(index!=posCar.size()) {
        S_CpuCar[0].setPosition(posCar[index++]);
    }
    const Vector2f &ciao=S_CpuCar[0].getPosition();
}

void Cars_Cpu::setCar(int x,int y) {

    //cout<<y<<endl;
    posCar.emplace_back(x,y);       //    posCar.push_back(Vector2f(x,y));
}

void Cars_Cpu::drawCpu(RenderWindow &window) {
    window.draw(S_CpuCar[0]);

}

const vector<Vector2f> &Cars_Cpu::getPosCar() const {
    return posCar;
}

void Cars_Cpu::setX_cpu(float x_cpu) {
    Cars_Cpu::x_cpu = x_cpu;
}

void Cars_Cpu::setY_cpu(float y_cpu) {
    Cars_Cpu::y_cpu = y_cpu;
}


