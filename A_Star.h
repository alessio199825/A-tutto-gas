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

    int x_start[16];
    int y_start[16];
    int x_end[16];
    int y_end[16];
    int vector_start[16];
    int vector_end[16];
    int trajectory_dim[7];
    int x_trajectory[300][7];
    int y_trajectory[300][7];

    int astar(int machine, int circuit);
    int getX_trajectory(int i, int machine);
    int getY_trajectory(int i, int machine);
    int getTrajectory_dim(int machine) const;




    MapSearchNode nodeEnd;

private:
    bool ChangeStart[7];
    bool done[7];



};


#endif //ALL_ULTIMO_GAS_A_STAR_H
