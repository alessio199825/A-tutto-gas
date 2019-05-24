//
// Created by alessio on 16/05/19.
//

#include "Control_Cpu.h"
#include <SFML/Graphics.hpp>

/*void Control_Cpu::Astar(bool done, Cars_Cpu &cars_cpu) {
    if(!done){

        AStarSearch<MapSearchNode> astarsearch;

        unsigned int SearchCount = 0;

        const unsigned int NumSearches = 1;

        while (SearchCount < NumSearches) {

            // Create a start state
            MapSearchNode nodeStart;
            nodeStart.x = static_cast<int>(cars_cpu.getX_cpu());
            nodeStart.y = static_cast<int>(cars_cpu.getY_cpu());
            cout << "Punto di partenza (" << nodeStart.x << "," << nodeStart.y << ")" << endl;

            // Define the goal state
            MapSearchNode nodeEnd;
            nodeEnd.x = 208;
            nodeEnd.y = 85;
            cout << "Punto di arrivo (" << nodeEnd.x << "," << nodeEnd.y << ")" << endl;

            // Set Start and goal states

            astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

            unsigned int SearchState;
            unsigned int SearchSteps = 0;

            do {

                SearchState = astarsearch.SearchStep();

                SearchSteps++;

//#if DEBUG_LISTS

                int len = 0;

                MapSearchNode *p = astarsearch.GetOpenListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *)p)->PrintNodeInfo();
#endif
                    p = astarsearch.GetOpenListNext();

                }

                cout << "Open list has " << len << " nodes\n";

                len = 0;

                cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
#endif
                    p = astarsearch.GetClosedListNext();
                }

                cout << "Closed list has " << len << " nodes\n";
#endif

            } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);





            if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
                cout << "Search found goal state\n";

                MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
                cout << "Displaying solution\n";
#endif
                int steps = 0;

                node->PrintNodeInfo();
                //Personaggio::Instance()->drawPersonaggio(window);
                //Mappa::Instance()->mostraMappa();
                for (;;) {
                    node = astarsearch.GetSolutionNext();



                    if (!node) {
                        break;
                    }


                    node->PrintNodeInfo();
                    //Personaggio::Instance()->drawPersonaggio(window);
                    //Mappa::Instance()->mostraMappa();
                    steps++;



                };

                cout << "Solution steps " << steps << endl;

                // Once you're done with the solution you can free the nodes up
                astarsearch.FreeSolutionNodes();


            } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
                cout << "Search terminated. Did not find goal state\n";

            }

            // Display the number of loops the search went through
            cout << "SearchSteps : " << SearchSteps << "\n";

            SearchCount++;

            astarsearch.EnsureMemoryFreed();
        }

    }
}*/

void Control_Cpu::LoadControlMap(RenderWindow &window, Error &error, int numcircuit) {

    /*try {
        if(!map) {
            switch (numcircuit) {
                case 1:
                    if (!ControlMap.loadFromFile("Control/controllo_astar1.bmp")) {
                        throw "impossibile caricare Texture";
                    }
                    break;
                case 2:
                    if (!ControlMap.loadFromFile("Control/controllo_astar2.bmp")) {
                        throw "impossibile caricare Texture";
                    }
                    break;
                case 3:
                    if (!ControlMap.loadFromFile("Control/controllo_astar3.bmp")) {
                        throw "impossibile caricare Texture";
                    }
                    break;
                default:
                    break;
            }

            map=true;
        }
        if(!example)
        if (!ExampleColor.loadFromFile("Control/controllo_astar1.bmp")) {
            throw "impossibile caricare Texture";
        }
        example=true;
    }
    catch(...){
        window.close();
        error.Check_Image(window);
    }*/

}


int Control_Cpu::GetCostNode(int x, int y) {

        if (!map) {
            if (!ControlMap.loadFromFile("Control/controllo_astar1.bmp")) {
                throw "impossibile caricare Texture";
            }

            if (!ExampleColor.loadFromFile("Control/controllo_astar1.bmp")) {
                throw "impossibile caricare Texture";
            }

            map = true;

        }

    Rosso = ExampleColor.getPixel(80, 90);
    Nero=ExampleColor.getPixel(290, 270);
    Giallo=ExampleColor.getPixel(153, 270);
    Colore=ControlMap.getPixel(static_cast<unsigned int>(x), static_cast<unsigned int>(y));

    if(Colore==Nero||Colore==Rosso)
        return 9;
    else if(Colore==Giallo)
        return 2;
    else
        return 1;
}




