
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        vis[row][col] = 1;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; ++i) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            
            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == '1') {
                dfs(nRow, nCol, grid, vis, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid, vis, m, n);
                }
            }
        }
        return cnt;
    }
};