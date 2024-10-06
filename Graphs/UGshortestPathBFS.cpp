#include <bits/stdc++.h> 
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> adj[N];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    
        queue<int> q;
        vector<int> dist(N, 1e9);
        q.push(src);
        dist[src] = 0;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
        
            for (auto it : adj[node]) {
                int distance = dist[node] + 1;
                if (distance < dist[it]) {
                    dist[it] = distance;
                    q.push(it);
                }
            }
        }
    
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
    
        return dist;
    }