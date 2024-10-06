#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> eff(m, vector<int>(n, 1e9));
        eff[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            if(row == m-1 && col == n-1) return diff;
            for(int i=0; i<4; i++){
                int newr = row + drow[i];
                int newc = col + dcol[i];
                if(newr >= 0 && newr < m && newc >= 0 && newc < n){
                    int newEffort = max(abs(heights[newr][newc] - heights[row][col]), diff);
                    if(newEffort < eff[newr][newc]){
                        eff[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};