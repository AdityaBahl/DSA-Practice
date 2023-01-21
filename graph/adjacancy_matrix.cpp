#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int adj[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // edge between u and v
        adj[u][v] = 1; // have it marked as 1
        adj[v][u] = 1; // have the alternate marked as 1
    }
    return 0;
}