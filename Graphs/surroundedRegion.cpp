#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int Row[], int Col[]){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int nRow = row + Row[i];
            int nCol = col + Col[i];
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && board[nRow][nCol] == 'O'){
                dfs(nRow, nCol, board, vis, Row, Col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int Row[] = {-1, 0, 1, 0};
        int Col[] = {0, 1, 0, -1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O'){
                    dfs(i, j, board, vis, Row, Col);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};