#include<bits/stdc++.h>
using namespace std;

int main(){

    int node, edge;
    cin >> node;
    cin >> edge;
    vector<vector<int>> adj(node+1, vector<int>(node+1, 0));
    for(int i=0; i<edge; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }


    return 0;
}