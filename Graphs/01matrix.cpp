#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int Row[] = {-1, 0, 1, 0};
        int Col[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto top = q.front();
            int r = top.first.first;
            int c = top.first.second;
            int d = top.second;
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = r + Row[i];
                int nCol = c + Col[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && mat[nRow][nCol] == 1){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, d+1});
                    dis[nRow][nCol] = d+1;
                }
            }
        }
        return dis;
    }
};