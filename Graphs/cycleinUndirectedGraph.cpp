#include <bits/stdc++.h> 
using namespace std;



bool detectCycle(int node, vector<int> adj[], int vis[]){
        queue<pair<int,int>> q;
        q.push({node, -1});
        vis[node] = 1;
        while(!q.empty()){
            auto top = q.front();
            int src = top.first;
            int parent = top.second;
            q.pop();
            for(auto it : adj[src]){
                if(!vis[it]){
                    q.push({it, src});
                    vis[it] = 1;
                }
                else if(it != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        //for connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis)) return true;
            }
        }
        return false;
    }