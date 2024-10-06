#include <bits/stdc++.h> 
using namespace std;


//bfs
void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, set<vector<pair<int,int>>>& s){
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        v.push_back({row-row, col-col});
        q.push({row, col});
        vis[row][col] = 1;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto top = q.front();
            int tRow = top.first;
            int tCol = top.second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nRow = tRow + dRow[i];
                int nCol = tCol + dCol[i];
            
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                    v.push_back({nRow-row, nCol-col});
                }
            }
        }
        s.insert(v);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(i, j, grid, vis, m, n, s);
                }
            }
        }
        return s.size();
    }


    //dfs
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& v, int m, int n, int bRow, int bCol){
        v.push_back({row-bRow, col-bCol});
        vis[row][col] = 1;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; ++i) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
            
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    dfs(nRow, nCol, grid, vis, v, m, n, bRow, bCol);
                }
            }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> v;
                    dfs(i, j, grid, vis, v, m, n, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }