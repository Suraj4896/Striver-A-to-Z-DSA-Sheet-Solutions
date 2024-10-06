#include <bits/stdc++.h> 
using namespace std;

//using simple dfs
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& nodeVis, vector<int>& pathVis, vector<int>& check){
        nodeVis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : graph[node]){
            if(!nodeVis[it]){
                if(dfs(it, graph, nodeVis, pathVis, check)) return true;
            }
            else if(pathVis[it]) return true;
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> nodeVis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);
        vector<int> safe;
        for(int i=0; i<n; i++){
            if(!nodeVis[i]){
                dfs(i, graph, nodeVis, pathVis, check);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]) safe.push_back(i);
        }
        return safe;
    }
};

//using toposort algo
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }