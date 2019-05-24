//
// Created by alessio on 20/05/19.
//

#include "A_Star.h"


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

    cout << str;
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
    //
    //
    ////TODO ERRORE NEL SETTAGGIO DELLA VARIBILE "NODE" CHE TRAMITE LA FUNZIONE SET CHIAMATA CON IL COSTRUTTORE DI MAPSEARCHNODE ASSEGNA UN VALORE NON COPRRISPONDENTE

    switch(node){

        case 1:                                                     // arrivo in alto a sinistra
            if ((GetMap(x - 1, y) < 9)
                && !((parent_x == x - 1) && (parent_y == y))
                    ) {
                NewNode = MapSearchNode(x - 1, y, 1);
                astarsearch->AddSuccessor(NewNode);
            }

            if ((GetMap(x, y - 1) < 9)
                && !((parent_x == x) && (parent_y == y - 1))
                    ) {
                NewNode = MapSearchNode(x, y - 1, 1);
                astarsearch->AddSuccessor(NewNode);
            }
            break;

            case 2:                                                 // arrivo in alto a destra
                if ((GetMap(x + 1, y) < 9)
                    && !((parent_x == x + 1) && (parent_y == y))
                        ) {
                    NewNode = MapSearchNode(x + 1, y, 2);
                    astarsearch->AddSuccessor(NewNode);
                }

            if ((GetMap(x, y - 1) < 9)
                && !((parent_x == x) && (parent_y == y - 1))
                    ) {
                NewNode = MapSearchNode(x, y - 1, 2);
                astarsearch->AddSuccessor(NewNode);
            }
            break;

        case 3:                                                     // arrivo in basso a destra
            if ((GetMap(x + 1, y) < 9)
                && !((parent_x == x + 1) && (parent_y == y))
                    ) {
                NewNode = MapSearchNode(x + 1, y, 3);
                astarsearch->AddSuccessor(NewNode);
            }

            if ((GetMap(x, y + 1) < 9)
                && !((parent_x == x) && (parent_y == y + 1))
                    ) {
                NewNode = MapSearchNode(x, y + 1, 3);
                astarsearch->AddSuccessor(NewNode);
            }
            break;

        case 4:                                                     // arrivo in basso a sinistra
            if ((GetMap(x, y + 1) < 9)
                && !((parent_x == x) && (parent_y == y + 1))
                    ) {
                NewNode = MapSearchNode(x, y + 1, 4);
                astarsearch->AddSuccessor(NewNode);
            }

            if ((GetMap(x - 1, y) < 9)
                && !((parent_x == x - 1) && (parent_y == y))
                    ) {
                NewNode = MapSearchNode(x - 1, y, 4);
                astarsearch->AddSuccessor(NewNode);

            }
            break;
        default:break;

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

    return control_cpu.GetCostNode(x,y);
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

A_Star::A_Star() {

}

int A_Star::astar()
{
    if(!done) {

        x_start[0]=160;
        y_start[0]=342;

        x_end[0]=164;
        y_end[0]=305;

        x_end[1]=168;
        y_end[1]=262;

        x_end[2]=174;
        y_end[2]=209;

        // "STL A* Search implementation\n(C)2001 Justin Heyes-Jones\n";

        // Our sample problem defines the world as a 2d array representing a terrain
        // Each element contains an integer from 0 to 5 which indicates the cost
        // of travel across the terrain. Zero means the least possible difficulty
        // in travelling (think ice rink if you can skate) whilst 5 represents the
        // most difficult. 9 indicates that we cannot pass.

        // Create an instance of the search class...

        AStarSearch<MapSearchNode> astarsearch;

        unsigned int SearchCount = 0;

        const unsigned int NumSearches = 1;

        while (SearchCount < NumSearches) {

            // Create a start state
            MapSearchNode nodeStart;
            nodeStart.x = x_start[vector_start];
            nodeStart.y = y_start[vector_start];

            // Define the goal state
            MapSearchNode nodeEnd;
            nodeEnd.x = x_end[vector_end];
            nodeEnd.y = y_end[vector_end];

            if(nodeStart.x >= nodeEnd.x && nodeStart.y >= nodeEnd.y){           //N-O
                nodeStart.setNode(1);
            }

            if(nodeStart.x <= nodeEnd.x && nodeStart.y >= nodeEnd.y){           //N-E
                nodeStart.setNode(2);
            }

            if(nodeStart.x <= nodeEnd.x && nodeStart.y <= nodeEnd.y){         //S-E
                nodeStart.setNode(3);
            }

            if(nodeStart.x >= nodeEnd.x && nodeStart.y <= nodeEnd.y){        //S-O
                nodeStart.setNode(4);
            }

            // Set Start and goal states

            astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

            unsigned int SearchState;
            unsigned int SearchSteps = 0;

            do {
                SearchState = astarsearch.SearchStep();

                SearchSteps++;

#if DEBUG_LISTS

                //cout << "Steps:" << SearchSteps << "\n";

                int len = 0;

                //cout << "Open:\n";
                MapSearchNode *p = astarsearch.GetOpenListStart();
                while (p) {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *) p)->PrintNodeInfo();
#endif
                    p = astarsearch.GetOpenListNext();

                }

                //cout << "Open list has " << len << " nodes\n";

                len = 0;

                //cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while (p) {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
#endif
                    p = astarsearch.GetClosedListNext();
                }

                //cout << "Closed list has " << len << " nodes\n";

#endif

            } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

            if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
                //cout << "Search found goal state\n";

                MapSearchNode *node = astarsearch.GetSolutionStart();

                done = true;

                if(vector_start<2) {
                    vector_start++;

                    x_start[vector_start] = x_end[vector_end];
                    y_start[vector_start] = y_end[vector_end];

                    vector_end++;

                    done=false;
                }

#if DISPLAY_SOLUTION
                cout << "Displaying solution\n";
#endif
                int steps = 0;

                node->PrintNodeInfo();
                for (;;) {
                    node = astarsearch.GetSolutionNext();

                    if (!node) {
                        break;
                    }

                    node->PrintNodeInfo();
                    steps++;

                };


                //cout << "Solution steps " << steps << endl;

                // Once you're done with the solution you can free the nodes up
                astarsearch.FreeSolutionNodes();


            } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
                //cout << "Search terminated. Did not find goal state\n";

            }

            // Display the number of loops the search went through
            //cout << "SearchSteps : " << SearchSteps << "\n";

            SearchCount++;

            astarsearch.EnsureMemoryFreed();
        }

        return 0;
    }
}

