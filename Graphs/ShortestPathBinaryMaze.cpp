#include <bits/stdc++.h> 
using namespace std;

//GFG
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int m = grid.size();
        int n = grid[0].size();
        int r1 = source.first;
        int c1 = source.second;
        int r2 = destination.first;
        int c2 = destination.second;
        int Row[] = {-1, 0, 1, 0};
        int Col[] = {0, 1, 0, -1};
        if(grid[r1][c1] == 0 || grid[r2][c2] == 0) return -1;
        queue<pair<int,pair<int, int>>> q;
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[r1][c1] = 0;
        q.push({0,source});
        while(!q.empty()){
            auto ele = q.front();
            int dist = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;

            if (row == r2 && col == c2) {
                return dist;
            }
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = row + Row[i];
                int nCol = col + Col[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n  && grid[nRow][nCol] == 1){
                    int newDist = dist + 1;
                    if(newDist < dis[nRow][nCol]){
                        dis[nRow][nCol] = newDist;
                        q.push({newDist, {nRow, nCol}});
                    }
                }
            }
        }
        return -1;
    }

//LeetCode
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        if(grid[0][0] != 0 || grid[m-1][m-1] != 0) return -1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(m, vector<int>(m, 1e9));
        dis[0][0] = 1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto ele = q.front();
            int dist = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;

            if (row == m-1 && col == m-1) {
                return dist;
            }
            q.pop();
            for(int drow=-1; drow<=1; drow++){
                for(int dcol=-1; dcol<=1; dcol++){
                    int nRow = row + drow;
                    int nCol = col + dcol;
                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < m  && grid[nRow][nCol] == 0){
                        int newDist = dist + 1;
                        if(newDist < dis[nRow][nCol]){
                            dis[nRow][nCol] = newDist;
                            q.push({newDist, {nRow, nCol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};