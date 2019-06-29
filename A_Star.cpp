//
// Created by alessio on 20/05/19.
//

#include "A_Star.h"

A_Star::A_Star() {

}

int A_Star::astar() {
    if (!done) {

        if (ChangeStart) {
            x_start[0] = 161;
            y_start[0] = 342;

            x_end[0] = 381;
            y_end[0] = 62;

            x_end[1] = 901;
            y_end[1] = 342;

            x_end[2] = 861;
            y_end[2] = 382;

            x_end[3] = 621;
            y_end[3] = 342;

            x_end[4] = 401;
            y_end[4] = 397;

            x_end[5] = 590;
            y_end[5] = 493;

            x_end[6] = 274;
            y_end[6] = 533;

            x_end[7] = 218;
            y_end[7] = 342;
            ChangeStart = false;
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
            nodeStart.x = x_start[vector_start];
            nodeStart.y = y_start[vector_start];

            // Define the goal state
            nodeEnd.x = x_end[vector_end];
            nodeEnd.y = y_end[vector_end];

            if (nodeStart.x >= nodeEnd.x && nodeStart.y >= nodeEnd.y) {           //N-O
                nodeStart.setNode(1);
            }

            if (nodeStart.x <= nodeEnd.x && nodeStart.y >= nodeEnd.y) {           //N-E
                nodeStart.setNode(2);
            }

            if (nodeStart.x <= nodeEnd.x && nodeStart.y <= nodeEnd.y) {         //S-E
                nodeStart.setNode(3);
            }

            if (nodeStart.x >= nodeEnd.x && nodeStart.y <= nodeEnd.y) {        //S-O
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
                if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING) {

                    x_tmp = nodeStart.x;
                    y_tmp = nodeStart.y;

                    x_start[vector_start] = x_tmp;
                    y_start[vector_start] = y_tmp;

                }
                }while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

                if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
                    //cout << "Search found goal state\n";

                    MapSearchNode *node = astarsearch.GetSolutionStart();

                    cout<<"ciao"<<endl;
                    done = true;

                    if (vector_start < 3) {
                        vector_start++;

                        if (vector_start == 3) {
                            ChangeStart = true;
                            vector_end = 0;
                        }

                        x_start[vector_start] = x_end[vector_end];
                        y_start[vector_start] = y_end[vector_end];

                        vector_end++;

                        done = false;
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


int A_Star::getX() {
    return x_tmp;
}

int A_Star::getY() {
    return y_tmp;
}