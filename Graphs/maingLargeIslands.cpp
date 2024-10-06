#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
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
    bool isValid(int newr, int newc, int n){
        return (newr < n && newr >= 0 && newc < n && newc >= 0);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0 , -1};
                for(int i=0; i<4; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int node = row * n + col;
                        int adjNode = newr * n + newc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int mx = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0 , -1};
                set<int> components;
                for(int i=0; i<4; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int totalSize = 1;
                for(auto it : components){
                    totalSize += ds.size[it];
                }
                mx = max(mx, totalSize);
            }
        }
        for(int cellNo=0; cellNo<n*n; cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};