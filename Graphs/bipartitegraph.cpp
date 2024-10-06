#include <bits/stdc++.h> 
using namespace std;

//bfs
class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& vis){
	    queue<int> q;
	    q.push(start);
	    vis[start] = 0;
	    while(!q.empty()){
	        int src = q.front();
	        q.pop();
	        for(auto it : graph[src]){
	            if(vis[it] == -1){
	                vis[it] = !vis[src];
	                q.push(it);
	            }
	            else if(vis[it] == vis[src]) return false;
	        }
	    }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
	    for(int i=0; i<n; i++){
	        if(vis[i] == -1){
	            if(bfs(i, graph, vis) == false) return false;
	        }
	    }
	    return true;
	}
    
};

//dfs
class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& vis, int color){
	    vis[start] = color;
	    for(auto it : graph[start]){
	        if(vis[it] == -1){
	            if(dfs(it, graph, vis, !color) == false) return false;
	        }
	        else if(vis[it] == vis[start]) return false;
	    }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
	    for(int i=0; i<n; i++){
	        if(vis[i] == -1){
	            if(dfs(i, graph, vis, 0) == false) return false;
	        }
	    }
	    return true;
	}
    
};