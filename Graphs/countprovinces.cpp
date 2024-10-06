#include<bits/stdc++.h>
using namespace std;


//dfs
class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;

        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        // convert the matrix to adjlist
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};

//Disjoint sets solution
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
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[0].size(); j++){
                if(adj[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int uniqueUP = 0;
        for(int i=0; i<V; i++){
            if(ds.findUPar(i) == i) uniqueUP++;
        }
        return uniqueUP;
    }
};