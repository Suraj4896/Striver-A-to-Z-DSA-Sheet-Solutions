#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int>& dfsList){
        vis[node] = 1;
        dfsList.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, dfsList);
        }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int start = 0;
    vector<int> dfsList;
    dfs(start, adj, vis, dfsList);
    return dfsList;
        
}