#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, 1e9));
        for(auto it : edges){
            grid[it[0]][it[1]] = it[2];
            grid[it[1]][it[0]] = it[2];
        }
        //floyd warshal
        for(int via=0; via<n; via++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                grid[i][j] = min(grid[i][j], grid[i][via]+grid[via][j]);
	            }
	        }
	    }
        
        int cntMin = INT_MAX; 
        int city;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(grid[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= cntMin){
                cntMin = cnt;
                city = i;
            }
        }
        return city;
    }
};