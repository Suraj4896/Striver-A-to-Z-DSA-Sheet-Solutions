#include <bits/stdc++.h> 
using namespace std;

void bfs(int sr, int sc, int newColor, vector<vector<int>>& image, vector<vector<int>>& vis){
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        int match = image[sr][sc];
        image[sr][sc] = newColor;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && image[nRow][nCol] == match){
                    vis[nRow][nCol] = 1;
                    image[nRow][nCol] = newColor;
                    q.push({nRow, nCol});
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        bfs(sr, sc, newColor, image, vis);
        return image;
    }