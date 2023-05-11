#include <bits/stdc++.h>
#define E 6
#define V 5
using namespace std;

/*Argument:- 
    node --> The node which is to be traverse
    visited[] --> the array marks whether a node is visited or not, also an array is always passed by reference
    ans --> Holds the DFS of the graph, which isnt necessary in this problem context
    count --> holds the number of vertex traverse, and it'll be less than actual no. of vertexes if its a disconnected Graph, else equal

    
*/
void dfs(int node, int visited[], vector<vector<int>> adjMatrix, vector<int> &ans, int &count)
{
    // visited[node] = 1;
    // ans.push_back(node);
    // count++;
    // // for (int i = 0; i < adjMatrix[node].size(); i++) --> long way of writing below for-loop
    // for (auto i : adjMatrix[node])
    // {
    //     if (visited[i] == 0)
    //     {
    //         dfs(i, visited, adjMatrix, ans, count);
    //     }
    // }
    visited[node] = 1;
    ans.push_back(node);
    count++;

    int numNodes = adjMatrix.size();
    for (int i = 0; i < numNodes; i++)
    {
        if (visited[i] == 0 && adjMatrix[node][i] > 0)
        {
            dfs(i, visited, adjMatrix, ans, count);
        }
    }
}

void discon0Rconnected(vector<vector<int>> adjMatrix)
{

    int count = 0;
    int visited[V] = {0};
    vector<int> ans;

    int startNode = 0;

    dfs(startNode, visited, adjMatrix, ans, count);

    if (count == V)
    {
        cout << "Graph is connected" << endl;
        
    }
    else
    {
        cout << "Graph is disconnected" << endl;
    }
}

int main()
{
    // Adj matrix with weights
    vector<vector<int>> adjMatrix = {{0, 2, 3, 0, 0},
                                     {2, 0, 15, 2, 0},
                                     {3, 15, 0, 0, 13},
                                     {0, 2, 0, 0, 9},
                                     {0, 0, 13, 9, 0}};

    discon0Rconnected(adjMatrix);

    return 0;
}