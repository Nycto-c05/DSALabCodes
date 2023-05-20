#include <iostream>
#include <queue>
using namespace std;

void breadthFirstSearch(int adjacency[][6], int visited[], int vertex, int source) {
    queue<int> q;
    visited[source] = 1;
    q.push(source);
    cout << source << " ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int j = 0; j < vertex; j++) {
            if (adjacency[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                cout << j << " ";
                q.push(j);
            }
        }
    }
    
}

void depthFirstSearchRecursive(int adjacency[][6], int visited[], int vertex, int node) {
    visited[node] = 1;
    cout << node << " ";

    for (int j = 0; j < vertex; j++) {
        if (adjacency[node][j] == 1 && visited[j] == 0) {
            depthFirstSearchRecursive(adjacency, visited, vertex, j);
        }
    }
}

int main() {
    int vertex = 6;
    int adjacency[6][6] = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    int visited1[vertex] = {0, 0, 0, 0, 0, 0};
    int visited2[vertex] = {0, 0, 0, 0, 0, 0};
    int source = 1;

    cout<<"BFS : ";
    breadthFirstSearch(adjacency, visited1, vertex, source);
    cout<<endl<<"DFS : ";
    depthFirstSearchRecursive(adjacency, visited2, vertex, source);

    return 0;
}
