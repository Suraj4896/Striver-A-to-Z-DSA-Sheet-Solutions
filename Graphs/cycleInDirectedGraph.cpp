#include <bits/stdc++.h> 
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& nodeVis, vector<int>& pathVis){
    nodeVis[node] = 1;
    pathVis[node] = 1;
        
    for(auto it : adj[node]){
        if(!nodeVis[it]){
            if(dfs(it, adj, nodeVis, pathVis)) return true;
        }
        else if(pathVis[it]) return true;
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> nodeVis(V,0);
    vector<int> pathVis(V,0);
        
    for(int i=0; i<V; i++){
        if(!nodeVis[i]){
            if(dfs(i, adj, nodeVis, pathVis)) return true;
        }
    }
    return false;
}