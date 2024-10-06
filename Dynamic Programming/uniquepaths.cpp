#include <bits/stdc++.h> 
using namespace std;


//recursion
class Solution {
public:
    int solve(int row, int col){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;

        int up = solve(row-1, col);
        int left = solve(row, col-1);

        return up + left;
    }
    int uniquePaths(int m, int n) {
        return solve(m-1, n-1);
    }
};

//memoization
class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int up = solve(row-1, col, dp);
        int left = solve(row, col-1, dp);

        return dp[row][col] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};

//tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//space optimisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};