#include <bits/stdc++.h> 
using namespace std;

//recursion
class Solution {
public:
    long long solve(int row, int col, vector<vector<int>>& grid){
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return INT_MAX;

        long long up = grid[row][col] + solve(row-1, col, grid);
        long long left = grid[row][col] + solve(row, col-1, grid);

        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(m-1, n-1, grid);
    }
};

//memoization
class Solution {
public:
    long long solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];

        long long up = grid[row][col] + solve(row-1, col, grid, dp);
        long long left = grid[row][col] + solve(row, col-1, grid, dp);

        return dp[row][col] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};

//tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    long long up = grid[i][j], left = grid[i][j];

                    if(i > 0) up += dp[i-1][j];
                    else up += INT_MAX;

                    if(j > 0) left += dp[i][j-1];
                    else left += INT_MAX;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//space optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{
                    long long up = grid[i][j], left = grid[i][j];

                    if(i > 0) up += prev[j];
                    else up += INT_MAX;

                    if(j > 0) left += temp[j-1];
                    else left += INT_MAX;
                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};