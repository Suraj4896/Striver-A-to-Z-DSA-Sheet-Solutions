#include <bits/stdc++.h> 
using namespace std;

void dfsTopo(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it.first]) dfsTopo(it.first, adj, vis, st);
	    }
	    st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        stack<int> st;
        vector<int> vis(N, 0);
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfsTopo(i, adj, vis, st);
            }
        }
        vector<int> dist(N, 1e9);
        int src = 0;
        dist[src] = 0;
        //O(N + M)
        while(!st.empty()){
            int dest = st.top();
            st.pop();
            for(auto it : adj[dest]){
                int distance = dist[dest] + it.second;
                dist[it.first] = min(distance, dist[it.first]);
            }
        }
        for(int i = 0; i < N; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }