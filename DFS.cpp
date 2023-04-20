#include <bits/stdc++.h>
using namespace std;

// TC --> O(E)
// SC --> O(V)

void dfs(int node, int visited[], vector<int> adj[], vector<int>& ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, ans);
        }
    }
}

// Disconnected and undirectional graph
vector<int> soln(int V, int E, vector<int> adj[])
{
    vector<int> ans;
    int visited[V] = {0};
    for (int i = 0; i < V; i++)//to account for disconnected graphs
    {
        int start = i;
        if (visited[i] == 0)
        {
            dfs(start, visited, adj, ans);
        }
    }
    return ans;
}

int main()
{
    int V = 9, E = 7;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(5);
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[2].push_back(5);
    adj[3].push_back(6);
    adj[4].push_back(7);
    adj[4].push_back(8);
    adj[7].push_back(4);
    adj[7].push_back(8);
    adj[8].push_back(4);
    adj[8].push_back(7);

    vector<int> ans = soln(V, E, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
