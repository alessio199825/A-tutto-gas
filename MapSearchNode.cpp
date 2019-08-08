//
// Created by alessio on 23/06/19.
//

#include "MapSearchNode.h"

// Definitions

bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{

    // same state in a maze search is simply when (x,y) are the same
    return (x == rhs.x) && (y == rhs.y);

}

void MapSearchNode::PrintNodeInfo()
{

    char str[100];
    sprintf( str, "Node position : (%d,%d)\n", x,y );
    //cout << str;
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal.

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{

    return (x == nodeGoal.x) && (y == nodeGoal.y);

}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node)
{
    int parent_x = -1;
    int parent_y = -1;

    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }

    MapSearchNode NewNode;

    // push each possible move except allowing the search to go backwards

    if( (GetMap( x - 20, y ) < 9)
        && !((parent_x == x-20) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode(x-20, y);
        astarsearch->AddSuccessor( NewNode );
    }

    if( (GetMap( x, y-20 ) < 9)
        && !((parent_x == x) && (parent_y == y-20))
            )
    {
        NewNode = MapSearchNode( x, y-20);
        astarsearch->AddSuccessor( NewNode );
    }

    if( (GetMap( x+20, y ) < 9)
        && !((parent_x == x+20) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x+20, y);
        astarsearch->AddSuccessor( NewNode );
    }


    if( (GetMap( x, y+20 ) < 9)
        && !((parent_x == x) && (parent_y == y+20))
            )
    {
        NewNode = MapSearchNode( x, y+20);
        astarsearch->AddSuccessor( NewNode );
    }

    return true;

}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is
// conceptually where we're moving

float MapSearchNode::GetCost( MapSearchNode &successor )
{
    return (float) GetMap( x, y );

}

int MapSearchNode::GetMap( int x, int y )
{
    if( x < 0 ||
        x >= 1000 ||
        y < 0 ||
        y >= 600
            )
    {
        return 9;
    }

    Tilemaps tilemaps;

    tilemaps.CreateMap();

    return tilemaps.TileNumber( x, y);
}


int MapSearchNode::getX() const {
    return x;
}

int MapSearchNode::getY() const {
    return y;
}

void MapSearchNode::setNode(int node) {
    MapSearchNode::node = node;
}

int MapSearchNode::getNode() const {
    return node;
}

