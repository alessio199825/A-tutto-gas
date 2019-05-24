//
// Created by alessio on 20/05/19.
//

#ifndef ALL_ULTIMO_GAS_A_STAR_H
#define ALL_ULTIMO_GAS_A_STAR_H

#include "stlastar.h" // See header for copyright and usage information

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Control_Cpu.h"
#include "Cars_Cpu.h"

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;

class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;

    int node;

    Control_Cpu control_cpu;
    Cars_Cpu cars_cpu;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py , int nodex) { x=px; y=py; node=nodex;}

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node);
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();
    int GetMap(int x, int y);

    int getX() const;

    int getY() const;

    void setNode(int node);

};

class A_Star{

public:

    A_Star();
    int astar();
    int x_start[3];
    int y_start[3];
    int x_end[3];
    int y_end[3];
    int vector_start=0;
    int vector_end=0;

private:
    bool done=false;

};

// Global data

// The world map



#endif //ALL_ULTIMO_GAS_A_STAR_H
