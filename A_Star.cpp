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

int A_Star::astar(int machine, int circuit) {
    if (!done[machine]) {

        if (ChangeStart[machine]) {
            switch(circuit) {
                case 1:
                switch (machine) {
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
                    default:
                        break;
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
                break;

                case 2:
                    switch (machine) {
                        case 0:
                            x_start[0] = 422;
                            y_start[0] = 76;
                            break;
                        case 1:
                            x_start[0] = 382;
                            y_start[0] = 36;
                            break;
                        case 2:
                            x_start[0] = 342;
                            y_start[0] = 76;
                            break;
                        case 3:
                            x_start[0] = 302;
                            y_start[0] = 36;
                            break;
                        case 4:
                            x_start[0] = 262;
                            y_start[0] = 76;
                            break;
                        default:
                            break;
                    }

                    x_end[1] = 882;
                    y_end[1] = 196;

                    x_end[2] = 462;
                    y_end[2] = 176;

                    x_end[3] = 842;
                    y_end[3] = 376;

                    x_end[4] = 422;
                    y_end[4] = 516;

                    x_end[5] = 202;
                    y_end[5] = 516;

                    x_end[6] = 82;
                    y_end[6] = 396;

                    x_end[7] = 102;
                    y_end[7] = 196;

                    x_end[8] = 262;
                    y_end[8] = 76;

                    x_end[9] = 882;
                    y_end[9] = 196;

                    ChangeStart[machine] = false;
                    break;
                case 3:
                    switch (machine) {
                        case 0:
                            x_start[0] = 572;
                            y_start[0] = 552;
                            break;
                        case 1:
                            x_start[0] = 612;
                            y_start[0] = 512;
                            break;
                        case 2:
                            x_start[0] = 652;
                            y_start[0] = 552;
                            break;
                        case 3:
                            x_start[0] = 692;
                            y_start[0] = 512;
                            break;
                        case 4:
                            x_start[0] = 732;
                            y_start[0] = 552;
                            break;
                        default:
                            break;
                    }

                    x_end[1] = 72;
                    y_end[1] = 432;

                    x_end[2] = 132;
                    y_end[2] = 332;

                    x_end[3] = 592;
                    y_end[3] = 412;

                    x_end[4] = 592;
                    y_end[4] = 332;

                    x_end[5] = 412;
                    y_end[5] = 332;

                    x_end[6] = 312;
                    y_end[6] = 232;

                    x_end[7] = 92;
                    y_end[7] = 212;

                    x_end[8] = 412;
                    y_end[8] = 52;

                    x_end[9] = 592;
                    y_end[9] = 212;

                    x_end[10] = 612;
                    y_end[10] = 72;

                    x_end[11] = 792;
                    y_end[11] = 132;

                    x_end[12] = 732;
                    y_end[12] = 272;

                    x_end[13] = 912;
                    y_end[13] = 332;

                    x_end[14] = 612;
                    y_end[14] = 512;

                    x_end[15] = 72;
                    y_end[15] = 432;

                    ChangeStart[machine] = false;
                    break;
                default: break;
            }
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

                    switch(circuit) {
                        case 1:
                            if (vector_start[machine] < 7) {
                                vector_start[machine]++;

                                x_start[vector_start[machine]] = x_end[vector_end[machine]];
                                y_start[vector_start[machine]] = y_end[vector_end[machine]];


                                vector_end[machine]++;

                                done[machine] = false;
                            }
                            break;
                        case 2:
                            if (vector_start[machine] < 8) {
                                vector_start[machine]++;

                                x_start[vector_start[machine]] = x_end[vector_end[machine]];
                                y_start[vector_start[machine]] = y_end[vector_end[machine]];


                                vector_end[machine]++;

                                done[machine] = false;
                            }
                            break;

                        case 3:
                            if (vector_start[machine] < 15) {
                                vector_start[machine]++;

                                x_start[vector_start[machine]] = x_end[vector_end[machine]];
                                y_start[vector_start[machine]] = y_end[vector_end[machine]];


                                vector_end[machine]++;

                                done[machine] = false;
                            }
                            break;
                        default:
                            break;
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




