#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

using namespace std;
using Coordinate = std::pair<int,int>;

const int MAX_PATH_NODES = 131072;


struct PathNode
{
    float pos[2]; // required
    bool isSpawner; // required
    
    // Add additional fields here if needed.
};

void bfs(int x, int y, float range, set<Coordinate>& reachable) 
{
    //allow us to move in all cardinal directions plus diagonally for a cost of sqrt(2)
    int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

    //a queue is the structure to use for bfs. the second value of the pair will allow us to hit a base case where we have moved beyond 16 units.
    queue<pair<Coordinate, float>> q; 
    q.push({{x, y}, range});

    while(!q.empty()) 
    {
        pair<Coordinate,float> current = q.front();
        q.pop();

        Coordinate coord = current.first;
        float remainingSteps = current.second;

        if (reachable.find(coord) != reachable.end() || remainingSteps<0)
            continue;

        reachable.insert(coord);

        //visit all adjacent cells
        for (int i=0;i<8;i++) 
        {
            float cost = 0;
            if(i < 4)
                cost = 1;
            else
                cost = sqrt(2);

            Coordinate nextCoord = {coord.first + dx[i], coord.second + dy[i]};
            q.push({nextCoord, remainingSteps - cost}); //put in the next coordinate, update cost so we can reach distance base case
        }
    }
}

set<Coordinate> getMoveSet(float spawn[], float range) 
{
    //a new approach to getting the moveset that allows for diagonal moves that can be made for an additional cost
    set<Coordinate> reachable;
    bfs((int)(spawn[0]), (int)(spawn[1]), range, reachable);
    return reachable;
}

/*
 * Complete the function below.
 */
int* GetReachableNodes(int nodeCount, PathNode* nodes, int* resultIndexCount) 
{
    set<int> indecies_set; // A set of indices to ensure uniqueness
    vector<Coordinate> destinations; // a list of destinations we want to compare to
    vector<PathNode> spawn_points; // A list of spawn points we can use to see if we're in range of one of them

    // Aggregate all spawn points and destinations
    for (int i = 0; i < nodeCount; i++) 
    {
        destinations.push_back(Coordinate(nodes[i].pos[0], nodes[i].pos[1]));
        if (nodes[i].isSpawner)
            spawn_points.push_back(nodes[i]);
    }

    // For each spawn point, check every node to see if it's within range.
    for (PathNode& spawnNode : spawn_points) 
    {
        for (int i = 0; i < nodeCount; i++) 
        {
            float distance = sqrt(pow(spawnNode.pos[0] - nodes[i].pos[0], 2) + pow(spawnNode.pos[1] - nodes[i].pos[1], 2));
            if (distance <= 16.0f) 
            {
                indecies_set.insert(i);
            }
        }
    }

    int* return_ptr = new int[indecies_set.size()];

    int index = 0;
    
    for (int value : indecies_set)
        return_ptr[index++] = value;

    *resultIndexCount = indecies_set.size();

    return return_ptr;
}



PathNode s_pathNodes[MAX_PATH_NODES];

int main() {
    s_pathNodes[0] = {{-10, 0}, false};
    s_pathNodes[1] = {{55, 100}, false};
    s_pathNodes[2] = {{-10, 10}, true};  
    s_pathNodes[3] = {{-20, 10}, false};
    s_pathNodes[4] = {{56, 110}, false};
    s_pathNodes[5] = {{4000, -3010}, true}; 
    s_pathNodes[6] = {{-20, 20}, true};  
    s_pathNodes[7] = {{-20, 30}, false};
    s_pathNodes[8] = {{55, 110}, false};
    s_pathNodes[9] = {{-10, 30}, true};
    s_pathNodes[10] = {{4010, -3010}, false};
    s_pathNodes[11] = {{40, 100}, false};
    s_pathNodes[12] = {{57, 110}, false};
    s_pathNodes[13] = {{4010, -3060}, false};
    s_pathNodes[14] = {{4010, -3015}, false};
    s_pathNodes[15] = {{4010, -3045}, false};
    s_pathNodes[16] = {{4010, -3030}, false};

    int nodeCount = 17;  // Total number of nodes in the dataset
    int resultCount = nodeCount;  // It can be at most as many as nodes.
    int* reachableNodes = GetReachableNodes(nodeCount, s_pathNodes, &resultCount);

    // Print out the results
    cout << "Reachable node indices:" << endl;
    for(int i = 0; i < resultCount; ++i)
    {
        cout << reachableNodes[i] << " ";
    }
    cout << endl;

    // Clean up the memory
    delete[] reachableNodes;

    return 0;
}

/*
0
2
3
5
6
7
9
10
13
14
15
16
*/

/*
-15, 0
*5, 0
30, 5
25, 0
-10, 0
0, 0
*/