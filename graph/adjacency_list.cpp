// vastly space efficient than matrix representation
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;       // edge between u and v
        adj[u].push_back(v); // have it marked as 1
        adj[v].push_back(u); // have the alternate marked as 1(for undirected graph only)
        // the above line isnt used for directed graph
    }
    return 0;
}