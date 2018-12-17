#ifndef ALL_ULTIMO_GAS_SETTING_H
#define ALL_ULTIMO_GAS_SETTING_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Setting {

public:
    Setting();
    bool setSettingState(Texture *T_setting, Sprite *S_setting);
    int getSettingPage(double& posx, double& posy);
    int getInstructions(double& posx, double& posy);
    bool setInstruction(Texture *T_setting, Sprite *S_setting);
    int get_Instruction_Return(double& posx, double& posy);
    int show_Instruction(Sprite *S_Instruction, Texture *T_Instruction, double *x_position, double *y_position, Clock *C_show);


protected:
    bool Instruction_ControlReturn=true;
    Clock C_returnIn;
    Time time_returnIn1, time_returnIn, Time_show;
    string controls;
    string Awards;
    string record;



};


#endif //ALL_ULTIMO_GAS_SETTING_H
