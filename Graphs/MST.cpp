#include <bits/stdc++.h> 
using namespace std;


//Prim's Algo
int spanningTree(int V, vector<vector<int>> adj[], vector<pair<int, int>> &MST)
    {
        //O(E)
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        //O(V)
        vector<int> vis(V, 0);
        pq.push({0,{0,-1}});
        int sum = 0;
        //E logE
        while(!pq.empty()){
            //logE
            auto it = pq.top();
            int edge = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            pq.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += edge;
            MST.push_back({parent, node});
            //E logE
            for(auto ele : adj[node]){
                int adjNode = ele[0];
                int wt = ele[1];
                if(!vis[adjNode]) pq.push({wt,{adjNode,node}});
            }
        }
        return sum;
    }




    //Kruskal's Algo
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    //union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    //union by size(more intutive)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};