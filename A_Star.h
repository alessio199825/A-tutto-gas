//
// Created by alessio on 20/05/19.
//

#ifndef ALL_ULTIMO_GAS_A_STAR_H
#define ALL_ULTIMO_GAS_A_STAR_H

#include "stlastar.h" // See header for copyright and usage information

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "MapSearchNode.h"

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;

class A_Star{

public:

    A_Star();
    int astar();
    int getX_trajectory(int i);
    int getY_trajectory(int i);
    int getTrajectory_dim() const;

    int x_start[8];
    int y_start[8];
    int x_end[9];
    int y_end[9];
    int vector_start=0;
    int vector_end=1;
    int trajectory_dim = 0;
    //int *x_trajectory = new int [trajectory_dim];
    //int *y_trajectory = new int [trajectory_dim];
    int x_trajectory[200];
    int y_trajectory[200];

    MapSearchNode nodeEnd;

private:
    bool ChangeStart=true;
    bool done=false;



};


#endif //ALL_ULTIMO_GAS_A_STAR_H
