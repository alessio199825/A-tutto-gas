#ifndef ALL_ULTIMO_GAS_SETTING_H
#define ALL_ULTIMO_GAS_SETTING_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Error.h"

using namespace sf;
using namespace std;

class Setting {

public:

    Setting();

    void setSettingState(RenderWindow &window, Error &error);
    int getSettingPage(double& posx, double& posy);
    int getInstructions(double& posx, double& posy);
    void setInstruction(RenderWindow &window, Error &error);
    int get_Instruction_Return(double& posx, double& posy);
    int show_Instruction(RenderWindow &window, Error &error);
    void draw_Instruction(RenderWindow &window);
    void setControl_C(bool control_C);

private:

    bool Instruction_ControlReturn=true, control_C;
    int ControlShow;
    double x_position=0, y_position=150;
    Clock C_returnIn, C_show;
    Time time_returnIn1, time_returnIn, Time_show;
    Texture T_setting[8], T_Instruction[6];
    Sprite S_setting[8], S_Instruction[6];

};


#endif //ALL_ULTIMO_GAS_SETTING_H
