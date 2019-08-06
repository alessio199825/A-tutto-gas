//
// Created by alessio on 18/12/18.
//

#include "Cars_Cpu.h"

Cars_Cpu::Cars_Cpu() = default;

void Cars_Cpu::createMachine(RenderWindow &window, Error &error) {

    if(i==0) {
        try {
            if (!T_CpuCar[0].loadFromFile("Cars_Cpu/macchina1.png")) {
                throw "impossibile caricare Texture";
            }

            if (!T_CpuCar[1].loadFromFile("Cars_Cpu/macchina2.png")) {
                throw "impossibile caricare Texture";
            }

            if (!T_CpuCar[2].loadFromFile("Cars_Cpu/macchina3.png")) {
                throw "impossibile caricare Texture";
            }

            if (!T_CpuCar[3].loadFromFile("Cars_Cpu/macchina4.png")) {
                throw "impossibile caricare Texture";
            }

            if (!T_CpuCar[4].loadFromFile("Cars_Cpu/macchina5.png")) {
                throw "impossibile caricare Texture";
            }

            if (!T_CpuCar[5].loadFromFile("Cars_Cpu/macchina6.png")) {
                throw "impossibile caricare Texture";
            }

            if (!T_CpuCar[6].loadFromFile("Cars_Cpu/macchina7.png")) {
                throw "impossibile caricare Texture";
            }
        }
        catch (...) {
            window.close();
            error.Check_Image(window);
        }
        i++;
    }
    for(int i=0; i<7; i++){

        S_CpuCar[i].setTexture(T_CpuCar[i]);
        S_CpuCar[i].setOrigin(9.5, 0);
        S_CpuCar[i].setRotation(180 + degreeCPU);

    }
   switch(circuit){
        case 1:
            x_cpu[0]=162;
            y_cpu[0]=368;

            x_cpu[1]=216;
            y_cpu[1]=340;

            x_cpu[2]=216;
            y_cpu[2]=390;

            x_cpu[3]=162;
            y_cpu[3]=418;

            x_cpu[4]=216;
            y_cpu[4]=444;

            x_cpu[5]=162;
            y_cpu[5]=468;

            x_cpu[6]=216;
            y_cpu[6]=494;
            break;
            }

    for(int i=0; i<7; i++) {
        S_CpuCar[i].setPosition(Vector2f(x_cpu[i], y_cpu[i]));
        window.draw(S_CpuCar[i]);
    }

    a_star.astar(&x_cpu[0], &y_cpu[0]);

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

    if((X_CPU[step] != x_cpu[0] || Y_CPU[step] != y_cpu[0]) && (X_CPU[step+1] != x_cpu[0] || Y_CPU[step+1] != y_cpu[0])) {

        time_Step = C_Step.getElapsedTime();

        if (time_Step.asMilliseconds() > 30) {          // aggiorna la posizione della macchina ogni TOT millisecondi


            if (Y_CPU[step] < Y_CPU[step - 1] && X_CPU[step] == X_CPU[step - 1]) {

                y_cpu[0] = y_cpu[0] - 2;
                step2=false;

                if (X_CPU[step + 1] > X_CPU[step - 1] && step+1 < dim_trajectory) {

                    x_cpu[0] = x_cpu[0] + 2;

                    if (degreeCPU < 45)
                        degreeCPU = degreeCPU + 5;

                    step2 = true;

                }

                else if (X_CPU[step + 1] < X_CPU[step - 1] && step+1 < dim_trajectory){

                    x_cpu[0] = x_cpu[0] - 2;
                    if(degreeCPU>-45)
                        degreeCPU = degreeCPU - 5;

                    step2=true;

                }
                else{

                    if(degreeCPU >=270 && degreeCPU <360){
                        degreeCPU = degreeCPU + 5;
                    }
                    else if(degreeCPU==360){
                        degreeCPU=0;
                    }
                    else if(degreeCPU<0)
                        degreeCPU = degreeCPU + 5;

                    else if(degreeCPU>0 )
                        degreeCPU = degreeCPU - 5;
                }

            }

            if (Y_CPU[step] > Y_CPU[step - 1] && X_CPU[step] == X_CPU[step - 1]) {

                y_cpu[0] = y_cpu[0] + 2;
                step2=false;



                if (X_CPU[step + 1] > X_CPU[step - 1] && step+1 < dim_trajectory){

                    x_cpu[0] = x_cpu[0] + 2;
                    if(degreeCPU>135)
                        degreeCPU = degreeCPU - 5;
                    step2=true;

                }

                else if (X_CPU[step + 1] < X_CPU[step - 1] && step+1 < dim_trajectory){

                    x_cpu[0] = x_cpu[0] - 2;
                    if(degreeCPU<225)
                        degreeCPU = degreeCPU + 5;
                    step2=true;

                }
                else{
                    if(degreeCPU<180)
                        degreeCPU = degreeCPU + 5;

                    if(degreeCPU>180)
                        degreeCPU = degreeCPU - 5;
                }


            }

            if (X_CPU[step] > X_CPU[step - 1] && Y_CPU[step] == Y_CPU[step - 1]){

                x_cpu[0] = x_cpu[0] + 2;
                step2=false;

                if (Y_CPU[step + 1] > Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu[0] = y_cpu[0] + 2;
                    if(degreeCPU<135)
                        degreeCPU = degreeCPU + 5;
                    step2=true;

                }

                else if (Y_CPU[step + 1] < Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu[0] = y_cpu[0] - 2;
                    if(degreeCPU>45)
                        degreeCPU = degreeCPU - 5;

                    step2=true;

                }
                else{
                    if(degreeCPU<90)
                        degreeCPU = degreeCPU + 5;

                    if(degreeCPU>90)
                        degreeCPU = degreeCPU - 5;
                }

            }

            if (X_CPU[step] < X_CPU[step - 1] && Y_CPU[step] == Y_CPU[step - 1]) {

                x_cpu[0] = x_cpu[0] - 2;
                step2=false;

                if (Y_CPU[step + 1] > Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu[0] = y_cpu[0] + 2;
                    if(degreeCPU>225)
                        degreeCPU = degreeCPU - 5;
                    step2=true;
                }

                else if (Y_CPU[step + 1] < Y_CPU[step - 1] && step+1 < dim_trajectory){

                    y_cpu[0] = y_cpu[0] - 2;
                    if(degreeCPU<315)
                        degreeCPU = degreeCPU + 5;
                    step2=true;

                }
                else{
                    if(degreeCPU<270)
                        degreeCPU = degreeCPU + 5;

                    if(degreeCPU>270)
                        degreeCPU = degreeCPU - 5;
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


    S_CpuCar[0].setPosition(x_cpu[0],y_cpu[0]);
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

void Cars_Cpu::setCircuit(int circuit) {
    Cars_Cpu::circuit = circuit;
}



