#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int Row[] = {-1, 0, 1, 0};
        int Col[] = {0, 1, 0, -1};
        int cntOne = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j] == 1) cntOne++;
            }
        }
        int time = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int r = top.first.first;
            int c = top.first.second;
            int t = top.second;
            time = max(time, t);
            for(int i=0; i<4; i++){
                int nRow = r + Row[i];
                int nCol = c + Col[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n  && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, t+1});
                    grid[nRow][nCol] = 2;
                    cntOne--;
                }
            }

        }
        if(cntOne != 0) return -1;
        return time;
    }
};