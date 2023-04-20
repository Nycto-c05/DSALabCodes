#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < vertex; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> bfs;
    queue<int> q;
    int vis[vertex] = {0};

    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }

    return bfs;
}

int main()
{
    int vertex = 9;
    vector<pair<int, int>> edges = {{0, 8}, {1, 6}, {1, 7}, {1, 8}, {5, 8}, {6, 0}, {7, 3}, {7, 4}, {8, 7}, {2, 5}};

    vector<int> bfs = BFS(vertex, edges);
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    return 0;
}
