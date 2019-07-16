//
// Created by alessio on 23/06/19.
//

#ifndef ALL_ULTIMO_GAS_MAPSEARCHNODE_H
#define ALL_ULTIMO_GAS_MAPSEARCHNODE_H


#include "stlastar.h"
#include "Tilemaps.h"
#include <fstream>
#include <iostream>


using namespace std;

class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;
    int node;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py;}

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

#endif //ALL_ULTIMO_GAS_MAPSEARCHNODE_H
