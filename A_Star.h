//
// Created by alessio on 20/05/19.
//

#ifndef ALL_ULTIMO_GAS_A_STAR_H
#define ALL_ULTIMO_GAS_A_STAR_H

#include "stlastar.h" // See header for copyright and usage information

#include <iostream>
#include <stdio.h>
#include <math.h>
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

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py , int nodex) { x=px; y=py; node=nodex;}

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node);
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );
    bool control_node = false;

    void PrintNodeInfo();
    int GetMap(int x, int y);

    int getX() const;

    int getY() const;

    void setNode(int node);

    int getNode() const;

};

class A_Star{

public:

    A_Star();
    int astar();
    int x_start[8];
    int y_start[8];
    int x_end[8];
    int y_end[8];
    int x_tmp, y_tmp;
    int vector_start=0;
    int vector_end=0;

    MapSearchNode nodeEnd;
    int getX();
    int getY();

private:
    bool ChangeStart=true;
    bool done=false;

};


#endif //ALL_ULTIMO_GAS_A_STAR_H
