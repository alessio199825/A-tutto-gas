//
// Created by alessio on 01/12/18.
//

#include "Control.h"

Control::Control() {

}

int Control::SetControl(int num_circuit, float y_CarPlayer, float x_CarPlayer, double degree_CarPlayer) {

    x_CarPlayer= static_cast<float>(x_CarPlayer + 38 * sin((degree_CarPlayer * M_PI) / 180));
    y_CarPlayer= static_cast<float>(y_CarPlayer - 38 * cos((degree_CarPlayer * M_PI) / 180));

    switch (num_circuit) {

        case 1:
            return CircuitOne_control(y_CarPlayer, x_CarPlayer);

        case 2:
            return CircuitThree_control(y_CarPlayer, x_CarPlayer);

        case 3:
            return CircuitTwo_control(y_CarPlayer, x_CarPlayer);

        default:
            return 0;

    }
}

int Control::CircuitOne_control(float y_CarPlayer, float x_CarPlayer) {


    if(x_CarPlayer<=368 && x_CarPlayer>=4 && y_CarPlayer<=145 && y_CarPlayer>=4){
        if(-401.01*pow(x_CarPlayer, 2)+(1453.29*x_CarPlayer*y_CarPlayer)-(1153.02*pow(y_CarPlayer,2))+(278190.9*x_CarPlayer)+(111658.53*y_CarPlayer)<52537085.79)
            return 1;
    }

    if(x_CarPlayer>368 && x_CarPlayer<=996 && y_CarPlayer<=113 && y_CarPlayer>4){
        if(-100.8173*pow(x_CarPlayer, 2)-(231.3200*x_CarPlayer*y_CarPlayer)-(529.9740*pow(y_CarPlayer,2))+(77763.5619*x_CarPlayer)+(212955.6939*y_CarPlayer)<15832739.0426)
            return 1;
    }

    if(x_CarPlayer>=505 && x_CarPlayer<=996 && y_CarPlayer<=159 && y_CarPlayer>113){
        if((y_CarPlayer>((x_CarPlayer*(-1.35))+842.24)) && (-199.9025*pow(x_CarPlayer, 2)-(586.7498*x_CarPlayer*y_CarPlayer)+(1084.6541*pow(y_CarPlayer,2))+(359516.3777*x_CarPlayer)+(225758.3708*y_CarPlayer)<146944590.4109))
            return 1;
    }

    if(x_CarPlayer>=540 && x_CarPlayer<=726 && y_CarPlayer>=365 && y_CarPlayer<=412) {
        if (y_CarPlayer > x_CarPlayer * (0.21) + 248)
            return 2;
    }

    if(x_CarPlayer>=127 && x_CarPlayer<=141 && y_CarPlayer>=264 && y_CarPlayer<=427) {
            return 2;
    }

    if(x_CarPlayer>=825 && x_CarPlayer<=996 && y_CarPlayer>159 && y_CarPlayer<=371){
        if(251.2521*pow(x_CarPlayer, 2)-(254.1112*x_CarPlayer*y_CarPlayer)+(1.6937*pow(y_CarPlayer,2))-(418262.3683*x_CarPlayer)+(253273.1399*y_CarPlayer)<-167077756.3042)
            return 1;
    }

    if(x_CarPlayer>=686 && x_CarPlayer<=996 && y_CarPlayer>=350 && y_CarPlayer<=596){
        if(-2026.89*pow(x_CarPlayer, 2)+(2158.67*x_CarPlayer*y_CarPlayer)-(1396.06*pow(y_CarPlayer,2))+(2606319.53*x_CarPlayer)-(1236555.0*y_CarPlayer)<729376627.88)
            return 1;
    }

    if(x_CarPlayer>=435 && x_CarPlayer<686 && y_CarPlayer>=349 && y_CarPlayer<=596){
        if((y_CarPlayer>x_CarPlayer*(0.65)-68.40) && (y_CarPlayer>x_CarPlayer*(-0.23)+495.73) && (y_CarPlayer<x_CarPlayer*(0.06)+369.52) && (-11.55*pow(x_CarPlayer, 2)-(93.77*x_CarPlayer*y_CarPlayer)-(53.35*pow(y_CarPlayer,2))+(49581.9*x_CarPlayer)+(116128.23*y_CarPlayer)<41125281.85))
            return 1;
    }

    if(x_CarPlayer>=324 && x_CarPlayer<=686 && y_CarPlayer>=464 && y_CarPlayer<=596){
        if((y_CarPlayer>x_CarPlayer*(-0.54)+776.72) && (321.3*pow(x_CarPlayer, 2)-(1280.97*x_CarPlayer*y_CarPlayer)+(573.50*pow(y_CarPlayer,2))+(444691.69*x_CarPlayer)+(426990.43*y_CarPlayer)>371855664.36))
            return 1;
    }

    if(x_CarPlayer>=140 && x_CarPlayer<=230 && y_CarPlayer>=522 && y_CarPlayer<=596){
        if(8.35*pow(x_CarPlayer, 2)-(39.06*x_CarPlayer*y_CarPlayer)+(3.70*pow(y_CarPlayer,2))+(21529.63*x_CarPlayer)-(56.12*y_CarPlayer)<1304298.29)
            return 1;
    }

    if(x_CarPlayer>=4 && x_CarPlayer<=145 && y_CarPlayer<=522 && y_CarPlayer>145){
        if(x_CarPlayer<145 && x_CarPlayer >53)
            return 1;
        else
            if(x_CarPlayer<=53)
                return 2;
    }

    if(x_CarPlayer>=234 && x_CarPlayer<=238 && y_CarPlayer>=151 && y_CarPlayer<=493){
        if((y_CarPlayer>-x_CarPlayer*(126.66)+29884.66))
            return 2;
    }

    if(x_CarPlayer>238 && x_CarPlayer<=434 && y_CarPlayer>=92 && y_CarPlayer<=284){
        if((60.14*pow(x_CarPlayer, 2)-(419.02*x_CarPlayer*y_CarPlayer)+(102.09*pow(y_CarPlayer,2))-(6060.58*x_CarPlayer)+(60993.37*y_CarPlayer)<-1556447.13) && (-753.81*pow(x_CarPlayer, 2)-(1833.85*x_CarPlayer*y_CarPlayer)-(1114.60*pow(y_CarPlayer,2))+(1083151.24*x_CarPlayer)+(1181543.70*y_CarPlayer)<354147437.09))
            return 2;
    }

    if(x_CarPlayer>434 && x_CarPlayer<726 && y_CarPlayer>198 && y_CarPlayer<=254){
        if((y_CarPlayer>-x_CarPlayer*(0.19)+337.23))
            return 2;
    }

    if(x_CarPlayer>=726 && x_CarPlayer<=892 && y_CarPlayer>=198 && y_CarPlayer<=376){
        if((y_CarPlayer>x_CarPlayer*(0.91)-465.50) && (-53.05*pow(x_CarPlayer, 2)+(292.76*x_CarPlayer*y_CarPlayer)-(178.05*pow(y_CarPlayer,2))-(16595.80*x_CarPlayer)-(129899.48*y_CarPlayer)>-32838428.11) && (y_CarPlayer<x_CarPlayer*(0.66)-181.63))
            return 2;
    }

    if(x_CarPlayer>=605 && x_CarPlayer<726 && y_CarPlayer>=230 && y_CarPlayer<=296){
        if(-37.48*pow(x_CarPlayer, 2)-(65.60*x_CarPlayer*y_CarPlayer)+(86.40*pow(y_CarPlayer,2))+(65895.20*x_CarPlayer)+(6702.25*y_CarPlayer)<23536944.53)
            return 2;
    }

    if(x_CarPlayer>=297 && x_CarPlayer<605 && y_CarPlayer>=255 && y_CarPlayer<=313){
        if((y_CarPlayer<-x_CarPlayer*(0.11)+333.02) || (y_CarPlayer<-x_CarPlayer*(2.66)+1289.0))
            return 2;
    }

    if(x_CarPlayer>=262 && x_CarPlayer<=404 && y_CarPlayer>=313 && y_CarPlayer<=491){
        if(-314.05*pow(x_CarPlayer, 2)+(195.16*x_CarPlayer*y_CarPlayer)-(2098.96*pow(y_CarPlayer,2))+(314006.0*x_CarPlayer)+(1580567.0*y_CarPlayer)<384309217.70)
            return 2;
    }

    if(x_CarPlayer>=329 && x_CarPlayer<=560 && y_CarPlayer>=489 && y_CarPlayer<=493)
        return 2;

    if(x_CarPlayer>=234 && x_CarPlayer<329 && y_CarPlayer>=480 && y_CarPlayer<=515){
        if(-84.12*pow(x_CarPlayer, 2)-(46.45*x_CarPlayer*y_CarPlayer)+(249.81*pow(y_CarPlayer,2))+(69748.85*x_CarPlayer)-(246574.43*y_CarPlayer)>-54487423.97)
            return 2;
    }

    if(x_CarPlayer>=996 || x_CarPlayer<=44 || y_CarPlayer>=596 || y_CarPlayer<=4)
        return 2;

    return 0;
}

int Control::CircuitTwo_control(float y_CarPlayer, float x_CarPlayer) {

    return 0;
}

int Control::CircuitThree_control(float y_CarPlayer, float x_CarPlayer) {

    return 0;
}


