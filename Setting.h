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
    bool setSettingState();
    int getSettingPage(double& posx, double& posy);
    int getInstructions(double& posx, double& posy);
    bool setInstruction();
    int get_Instruction_Return(double& posx, double& posy);
    int show_Instruction(double *x_position, double *y_position, Clock *C_show);
    const Sprite getS_setting(int i) const;

    const Sprite getS_Instruction(int i) const;

protected:
    bool Instruction_ControlReturn=true;
    Clock C_returnIn;
    Time time_returnIn1, time_returnIn, Time_show;
    string controls;
    string Awards;
    string record;

private:
    Texture T_setting[8], T_Instruction[6];
    Sprite S_setting[8], S_Instruction[6];
};


#endif //ALL_ULTIMO_GAS_SETTING_H
