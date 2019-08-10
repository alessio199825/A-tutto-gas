//
// Created by alessio on 18/12/18.
//

#include "Cars_Cpu.h"
#include "Load_Exception.h"

Cars_Cpu::Cars_Cpu()
{
    for(int i=0; i<5; i++){
        step[i] = 1;
        step2[i] = false;
        dim_tmp[i] = 0;
        lap[i] = 0;
    }
}

bool Cars_Cpu::createMachine(RenderWindow &window, Error &error) {

    if(i==0) {
        try {
            if (!T_CpuCar[0].loadFromFile("Cars_Cpu/macchina6.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }

            if (!T_CpuCar[1].loadFromFile("Cars_Cpu/macchina7.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }

            if (!T_CpuCar[2].loadFromFile("Cars_Cpu/macchina3.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }

            if (!T_CpuCar[3].loadFromFile("Cars_Cpu/macchina4.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }

            if (!T_CpuCar[4].loadFromFile("Cars_Cpu/macchina5.png")) {
                throw Load_exception("Load_exception:Impossibile caricare file");
            }

        }
        catch (Load_exception e) {
            window.close();
            error.Check_Image(window);
        }
        i++;
    }

   switch(circuit){
        case 1:
            for(int i=0; i<5; i++){
                degreeCPU[i] = 0;
            }

            x_cpu[0]=222;
            y_cpu[0]=348;

            x_cpu[1]=162;
            y_cpu[1]=388;

            x_cpu[2]=222;
            y_cpu[2]=428;

            x_cpu[3]=162;
            y_cpu[3]=468;

            x_cpu[4]=222;
            y_cpu[4]=508;

           break;
        case 2:
            for(int i=0; i<5; i++){
                degreeCPU[i] = 90;
            }
           break;
        case 3:
            for(int i=0; i<5; i++){
                degreeCPU[i] = -90;
            }
            break;
       default:break;
            }

    for(int i=0; i<5; i++){

        S_CpuCar[i].setTexture(T_CpuCar[i]);
        S_CpuCar[i].setOrigin(9.5, 0);
        S_CpuCar[i].setRotation(180 + degreeCPU[i]);

    }


    for(int i=0; i<5; i++) {
        S_CpuCar[i].setPosition(Vector2f(x_cpu[i], y_cpu[i]));
        window.draw(S_CpuCar[i]);
    }



    for(carNumber=0; carNumber<5; carNumber++) {
        a_star.astar(carNumber);
        dim_trajectory[carNumber] = a_star.getTrajectory_dim(carNumber);
    }
    for(carNumber=0; carNumber<5; carNumber++) {

        for (int i = dim_tmp[carNumber]; i < dim_trajectory[carNumber]; i++) {

            X_CPU[i][carNumber] = a_star.getX_trajectory(i, carNumber);
            Y_CPU[i][carNumber] = a_star.getY_trajectory(i, carNumber);

        }

        dim_tmp[carNumber] = dim_trajectory[carNumber];
    }

    return dim_trajectory[3] == 185;

}

void Cars_Cpu::moveCar() {        //gestire bene setCar e move Car che forse fanno la stessa cosa

    if(step[0] == 176)
        step[0] = 24;
    if(step[1] == 181)
        step[1] = 27;
    if(step[2] == 180)
        step[2] = 27;
    if(step[3] == 185)
        step[3] = 32;
    if(step[4] == 184)
        step[4] = 31;


    for (carNumber = 0; carNumber < 5; carNumber++ ) {

        if ((X_CPU[step[carNumber]][carNumber] != x_cpu[carNumber] || Y_CPU[step[carNumber]][carNumber] != y_cpu[carNumber]) &&
            (X_CPU[step[carNumber] + 1][carNumber] != x_cpu[carNumber] ||
             Y_CPU[step[carNumber] + 1][carNumber] != y_cpu[carNumber])) {

            time_Step[carNumber] = C_Step[carNumber].getElapsedTime();

            if (time_Step[carNumber].asMilliseconds() >
                30) {          // aggiorna la posizione della macchina ogni TOT millisecondi


                if (Y_CPU[step[carNumber]][carNumber] < Y_CPU[step[carNumber] - 1][carNumber] &&
                    X_CPU[step[carNumber]][carNumber] == X_CPU[step[carNumber] - 1][carNumber]) {

                    y_cpu[carNumber] = y_cpu[carNumber] - 2;
                    step2[carNumber] = false;

                    if (X_CPU[step[carNumber] + 1][carNumber] > X_CPU[step[carNumber] - 1][carNumber] &&
                        step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        x_cpu[carNumber] = x_cpu[carNumber] + 2;

                        if (degreeCPU[carNumber] < 45)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;

                        step2[carNumber] = true;

                    } else if (X_CPU[step[carNumber] + 1][carNumber] < X_CPU[step[carNumber] - 1][carNumber] &&
                               step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        x_cpu[carNumber] = x_cpu[carNumber] - 2;
                        if (degreeCPU[carNumber] > -45)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;

                        step2[carNumber] = true;

                    } else {

                        if (degreeCPU[carNumber] >= 270 && degreeCPU[carNumber] < 360) {
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;
                        } else if (degreeCPU[carNumber] == 360) {
                            degreeCPU[carNumber] = 0;
                        } else if (degreeCPU[carNumber] < 0)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;

                        else if (degreeCPU[carNumber] > 0)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;
                    }

                }

                if (Y_CPU[step[carNumber]][carNumber] > Y_CPU[step[carNumber] - 1][carNumber] &&
                    X_CPU[step[carNumber]][carNumber] == X_CPU[step[carNumber] - 1][carNumber]) {

                    y_cpu[carNumber] = y_cpu[carNumber] + 2;
                    step2[carNumber] = false;


                    if (X_CPU[step[carNumber] + 1][carNumber] > X_CPU[step[carNumber] - 1][carNumber] &&
                        step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        x_cpu[carNumber] = x_cpu[carNumber] + 2;
                        if (degreeCPU[carNumber] > 135)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;
                        step2[carNumber] = true;

                    } else if (X_CPU[step[carNumber] + 1][carNumber] < X_CPU[step[carNumber] - 1][carNumber] &&
                               step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        x_cpu[carNumber] = x_cpu[carNumber] - 2;
                        if (degreeCPU[carNumber] < 225)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;
                        step2[carNumber] = true;

                    } else {
                        if (degreeCPU[carNumber] < 180)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;

                        if (degreeCPU[carNumber] > 180)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;
                    }


                }

                if (X_CPU[step[carNumber]][carNumber] > X_CPU[step[carNumber] - 1][carNumber] &&
                    Y_CPU[step[carNumber]][carNumber] == Y_CPU[step[carNumber] - 1][carNumber]) {

                    x_cpu[carNumber] = x_cpu[carNumber] + 2;
                    step2[carNumber] = false;

                    if (Y_CPU[step[carNumber] + 1][carNumber] > Y_CPU[step[carNumber] - 1][carNumber] &&
                        step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        y_cpu[carNumber] = y_cpu[carNumber] + 2;
                        if (degreeCPU[carNumber] < 135)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;
                        step2[carNumber] = true;

                    } else if (Y_CPU[step[carNumber] + 1][carNumber] < Y_CPU[step[carNumber] - 1][carNumber] &&
                               step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        y_cpu[carNumber] = y_cpu[carNumber] - 2;
                        if (degreeCPU[carNumber] > 45)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;

                        step2[carNumber] = true;

                    } else {
                        if (degreeCPU[carNumber] < 90)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;

                        if (degreeCPU[carNumber] > 90)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;
                    }

                }

                if (X_CPU[step[carNumber]][carNumber] < X_CPU[step[carNumber] - 1][carNumber] &&
                    Y_CPU[step[carNumber]][carNumber] == Y_CPU[step[carNumber] - 1][carNumber]) {


                    x_cpu[carNumber] = x_cpu[carNumber] - 2;
                    step2[carNumber] = false;

                    if (Y_CPU[step[carNumber] + 1][carNumber] > Y_CPU[step[carNumber] - 1][carNumber] &&
                        step[carNumber] + 1 < dim_trajectory[carNumber]) {
                        y_cpu[carNumber] = y_cpu[carNumber] + 2;

                        if (degreeCPU[carNumber] > 225)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;
                        step2[carNumber] = true;
                    } else if (Y_CPU[step[carNumber] + 1][carNumber] < Y_CPU[step[carNumber] - 1][carNumber] &&
                               step[carNumber] + 1 < dim_trajectory[carNumber]) {

                        y_cpu[carNumber] = y_cpu[carNumber] - 2;
                        if (degreeCPU[carNumber] < 315)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;
                        step2[carNumber] = true;

                    } else {
                        if (degreeCPU[carNumber] < 270)
                            degreeCPU[carNumber] = degreeCPU[carNumber] + 5;

                        if (degreeCPU[carNumber] > 270)
                            degreeCPU[carNumber] = degreeCPU[carNumber] - 5;
                    }

                }

                C_Step[carNumber].restart();
            }
        } else {
            step[carNumber] = step[carNumber] + 1;

            if (step2[carNumber])
                step[carNumber] = step[carNumber] + 1;

        }


        S_CpuCar[carNumber].setPosition(x_cpu[carNumber], y_cpu[carNumber]);
        S_CpuCar[carNumber].setRotation(180 + degreeCPU[carNumber]);
    }


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
    for(int i=0; i<5; i++) {
        window.draw(S_CpuCar[i]);
    }
}

const vector<Vector2f> &Cars_Cpu::getPosCar() const {
    return posCar;
}

void Cars_Cpu::setCircuit(int circuit) {
    Cars_Cpu::circuit = circuit;
}


int Cars_Cpu::getPosition(int giri, int &position) {

    if(giri != 3 && giri != 5 && giri != 10){
        giri = 3;
    }

    for(int i=0; i<5; i++){

        if(y_cpu[i] >= 410 && x_cpu[i] >= 465 && y_cpu[i] <= 490 && x_cpu[i] <= 470){
            intermediate[i] = intermediate[i] + 1;
            if(intermediate[i] > lap[i]){
                intermediate[i] = lap[i];
            }
        }

        if(y_cpu[i] >= 255 && y_cpu[i] <= 269 && x_cpu[i] >=143 && x_cpu[i] <= 236 && lap[i] == intermediate[i]) {
            lap[i] = lap[i] + 1;
            if (lap[i] == giri + 1) {
                vector_position[i] = position;
                position++;
                cout<<position<<endl;

            }
        }
    }
    return vector_position[5];
}

const int Cars_Cpu::getVector_position(int i) {
    return vector_position[i];
}




