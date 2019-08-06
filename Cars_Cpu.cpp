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
    S_CpuCar[0].setRotation(180 + degreeCPU);

    S_CpuCar[0].setPosition(Vector2f(x_cpu, y_cpu));
    for(int i=0; i<1; i++)
        window.draw(S_CpuCar[i]);

    a_star.astar();

    dim_trajectory = a_star.getTrajectory_dim();

    for (int i = dim_tmp; i < dim_trajectory; i++) {

        X_CPU[i] = a_star.getX_trajectory(i);
        Y_CPU[i] = a_star.getY_trajectory(i);
    }

    dim_tmp=dim_trajectory;

}

void Cars_Cpu::moveCar() {        //gestire bene setCar e move Car che forse fanno la stessa cosa

    if(step == 180){
        step=28;
    }

    if((X_CPU[step] != x_cpu || Y_CPU[step] != y_cpu) && (X_CPU[step+1] != x_cpu || Y_CPU[step+1] != y_cpu)) {

        time_Step = C_Step.getElapsedTime();

        if (time_Step.asMilliseconds() > 30) {          // aggiorna la posizione della macchina ogni TOT millisecondi


            if (Y_CPU[step] < Y_CPU[step - 1] && X_CPU[step] == X_CPU[step - 1]) {

                y_cpu = y_cpu - 2;
                step2=false;

                if (X_CPU[step + 1] > X_CPU[step - 1] && step+1 < dim_trajectory) {

                    x_cpu = x_cpu + 2;

                    if (degreeCPU < 45)
                        degreeCPU = degreeCPU + 3;

                    step2 = true;

                }

                else if (X_CPU[step + 1] < X_CPU[step - 1] && step+1 < dim_trajectory){

                    x_cpu = x_cpu - 2;
                    if(degreeCPU>-45)
                        degreeCPU = degreeCPU - 3;

                    step2=true;

                }
                else{

                    if(degreeCPU >=270 && degreeCPU <360){
                        degreeCPU = degreeCPU + 3;
                    }
                    else if(degreeCPU==360){
                        degreeCPU=0;
                    }
                    else if(degreeCPU<0)
                        degreeCPU = degreeCPU + 3;

                    else if(degreeCPU>0 )
                        degreeCPU = degreeCPU - 3;
                }

            }

            if (Y_CPU[step] > Y_CPU[step - 1] && X_CPU[step] == X_CPU[step - 1]) {

                y_cpu = y_cpu + 2;
                step2=false;



                if (X_CPU[step + 1] > X_CPU[step - 1] && step+1 < dim_trajectory){

                    x_cpu = x_cpu + 2;
                    if(degreeCPU>135)
                        degreeCPU = degreeCPU - 3;
                    step2=true;

                }

                else if (X_CPU[step + 1] < X_CPU[step - 1] && step+1 < dim_trajectory){

                    x_cpu = x_cpu - 2;
                    if(degreeCPU<225)
                        degreeCPU = degreeCPU + 3;
                    step2=true;

                }
                else{
                    if(degreeCPU<180)
                        degreeCPU = degreeCPU + 3;

                    if(degreeCPU>180)
                        degreeCPU = degreeCPU - 3;
                }


            }

            if (X_CPU[step] > X_CPU[step - 1] && Y_CPU[step] == Y_CPU[step - 1]){

                x_cpu = x_cpu + 2;
                step2=false;

                if (Y_CPU[step + 1] > Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu = y_cpu + 2;
                    if(degreeCPU<135)
                        degreeCPU = degreeCPU + 3;
                    step2=true;

                }

                else if (Y_CPU[step + 1] < Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu = y_cpu - 2;
                    if(degreeCPU>45)
                        degreeCPU = degreeCPU - 3;

                    step2=true;

                }
                else{
                    if(degreeCPU<90)
                        degreeCPU = degreeCPU + 3;

                    if(degreeCPU>90)
                        degreeCPU = degreeCPU - 3;
                }

            }

            if (X_CPU[step] < X_CPU[step - 1] && Y_CPU[step] == Y_CPU[step - 1]) {

                x_cpu = x_cpu - 2;
                step2=false;

                if (Y_CPU[step + 1] > Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu = y_cpu + 2;
                    if(degreeCPU>225)
                        degreeCPU = degreeCPU - 3;
                    step2=true;
                }

                else if (Y_CPU[step + 1] < Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu = y_cpu - 2;
                    if(degreeCPU<315)
                        degreeCPU = degreeCPU + 3;
                    step2=true;

                }
                else{
                    if(degreeCPU<270)
                        degreeCPU = degreeCPU + 3;

                    if(degreeCPU>270)
                        degreeCPU = degreeCPU - 3;
                }

            }

            C_Step.restart();
        }
    }

    else {
        step++;

        if(step2)
            step++;

    }


    S_CpuCar[0].setPosition(x_cpu,y_cpu);
    S_CpuCar[0].setRotation(180 + degreeCPU);


}

void Cars_Cpu::setPos() {


    if(index!=posCar.size()) {
        S_CpuCar[0].setPosition(posCar[index++]);
    }
    const Vector2f &ciao=S_CpuCar[0].getPosition();
}

void Cars_Cpu::setCar(int x,int y) {

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


