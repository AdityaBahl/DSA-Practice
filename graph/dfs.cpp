#include <bits/stdc++.h>
using namespace std;
class solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for (auto pr : adj[node])
        {
            if (!vis[pr])
            {
                dfs(pr, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};
int main()
{
    return 0;
}