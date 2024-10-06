#include <bits/stdc++.h> 
using namespace std;

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
    bool isValid(int nrow, int ncol, int n, int m){
        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet d(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        vector<int> ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            count++;
            
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(isValid(nrow, ncol, n, m)){
                    if(vis[nrow][ncol] == 1){
                        int node = row * m + col;
                        int adjNode = nrow * m + ncol;
                        if(d.findUPar(node) != d.findUPar(adjNode)){
                            count--;
                            d.unionBySize(node, adjNode);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};