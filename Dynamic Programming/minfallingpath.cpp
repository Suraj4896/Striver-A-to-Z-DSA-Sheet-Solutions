#include <bits/stdc++.h> 
using namespace std;

//recursion
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(j < 0 || j >= matrix[0].size()) return 1e8;
        if(i == 0) return matrix[i][j];

        int up = matrix[i][j] + solve(i-1, j, matrix);
        int rd = matrix[i][j] + solve(i-1, j+1, matrix);
        int ld = matrix[i][j] + solve(i-1, j-1, matrix);

        return min(up, min(rd, ld));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e8;
        for(int j=0; j<n; j++){
            mini = min(mini, solve(m-1, j, matrix));
        }
        return mini;
    }
};

//memoization
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >= matrix[0].size()) return 1e8;
        if(i == 0) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + solve(i-1, j, matrix, dp);
        int rd = matrix[i][j] + solve(i-1, j+1, matrix, dp);
        int ld = matrix[i][j] + solve(i-1, j-1, matrix, dp);

        return dp[i][j] = min(up, min(rd, ld));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = 1e8;
        for(int j=0; j<n; j++){
            mini = min(mini, solve(m-1, j, matrix, dp));
        }
        return mini;
    }
};

//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int rd = matrix[i][j];
                if(j+1 < m) rd += dp[i-1][j+1];
                else rd += 1e8;
                int ld = matrix[i][j];
                if(j-1 >= 0) ld += dp[i-1][j-1];
                else ld += 1e8;
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int mini = 1e8;
        for(int j=0; j<n; j++){
            mini = min(mini, dp[m-1][j]);
        }
        return mini;
    }
};

//space optimisation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0);
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + prev[j];
                int rd = matrix[i][j];
                if(j+1 < m) rd += prev[j+1];
                else rd += 1e8;
                int ld = matrix[i][j];
                if(j-1 >= 0) ld += prev[j-1];
                else ld += 1e8;
                curr[j] = min(up, min(ld, rd));
            }
            prev = curr;
        }
        int mini = 1e8;
        for(int j=0; j<n; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};