//
// Created by alessio on 20/05/19.
//

#include "A_Star.h"

A_Star::A_Star(){
    for(int i=0; i<7; i++) {
        ChangeStart[i] = true;
        trajectory_dim[i] = 0;
        done[i] = false;
        vector_start[i] = 0;
        vector_end[i] = 1;
    }
};

int A_Star::astar(int machine) {
    if (!done[machine]) {

        if (ChangeStart[machine]) {
            switch(machine){
                case 0:
                    x_start[0] = 222;
                    y_start[0] = 348;
                    break;
                case 1:
                    x_start[0] = 162;
                    y_start[0] = 388;
                    break;
                case 2:
                    x_start[0] = 222;
                    y_start[0] = 428;
                    break;
                case 3:
                    x_start[0] = 162;
                    y_start[0] = 468;
                    break;
                case 4:
                    x_start[0] = 222;
                    y_start[0] = 508;
                    break;
                case 5:
                    x_start[0] = 162;
                    y_start[0] = 528;
                    break;
                case 6:
                    x_start[0] = 222;
                    y_start[0] = 568;
                    break;
                default:break;
            }



            x_end[1] = 382;
            y_end[1] = 68;

            x_end[2] = 942;
            y_end[2] = 388;

            x_end[3] = 782;
            y_end[3] = 388;

            x_end[4] = 502;
            y_end[4] = 328;

            x_end[5] = 482;
            y_end[5] = 448;

            x_end[6] = 182;
            y_end[6] = 508;

            x_end[7] = 182;
            y_end[7] = 368;

            x_end[8] = 382;
            y_end[8] = 68;

            ChangeStart[machine] = false;
        }

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
            nodeStart.x = x_start[vector_start[machine]];
            nodeStart.y = y_start[vector_start[machine]];

            // Define the goal state

            nodeEnd.x = x_end[vector_end[machine]];
            nodeEnd.y = y_end[vector_end[machine]];

            // Set Start and goal states

            astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

            unsigned int SearchState;
            unsigned int SearchSteps = 0;

            do {
                SearchState = astarsearch.SearchStep();

                SearchSteps++;


#if DEBUG_LISTS


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
            }
                while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

                if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
                    //cout << "Search found goal state\n";

                    MapSearchNode *node = astarsearch.GetSolutionStart();

                    done[machine] = true;

                    if (vector_start[machine] < 7) {
                        vector_start[machine]++;

                        x_start[vector_start[machine]] = x_end[vector_end[machine]];
                        y_start[vector_start[machine]] = y_end[vector_end[machine]];


                        vector_end[machine]++;

                        done[machine] = false;
                    }

#if DISPLAY_SOLUTION
                    cout << "Displaying solution\n";
#endif
                    int steps = 0;

                    node->PrintNodeInfo();

                    x_trajectory[trajectory_dim[machine]][machine]=node->x;
                    y_trajectory[trajectory_dim[machine]][machine]=node->y;


                    for (;;) {

                        trajectory_dim[machine] = trajectory_dim[machine] + 1;

                        node = astarsearch.GetSolutionNext();

                        if (!node) {
                            break;
                        }

                        x_trajectory[trajectory_dim[machine]][machine]=node->x;
                        y_trajectory[trajectory_dim[machine]][machine]=node->y;

                        //cout<<machine <<"="<<x_trajectory[trajectory_dim[machine]][machine]<<endl;


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

        return 0;
    }


int A_Star::getX_trajectory(int i, int machine) {

    return x_trajectory[i][machine];
}

int A_Star::getY_trajectory(int i, int machine) {
    return y_trajectory[i][machine];
}

int A_Star::getTrajectory_dim(int machine) const {
    return trajectory_dim[machine];
}




