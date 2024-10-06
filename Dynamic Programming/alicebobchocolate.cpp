#include <bits/stdc++.h> 
using namespace std;

//recursion
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid){
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e8;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + solve(i+1, j1+dj1, j2+dj2, r, c, grid));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1+dj1, j2+dj2, r, c, grid));
            }
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return solve(0, 0, c-1, r, c, grid);
}

//memoization
#include <bits/stdc++.h> 

int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e8;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + solve(i+1, j1+dj1, j2+dj2, r, c, grid, dp));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1+dj1, j2+dj2, r, c, grid, dp));
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c-1, r, c, grid, dp);
}

//tabulation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Initialize the DP array for the last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj]; // Include the DP result from the next row

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                dp[i][j1][j2] = maxi; // Store the maximum result for this state in the DP array
            }
        }
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return dp[0][0][m - 1];
}

//space optimisation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create two 2D vectors 'front' and 'cur' to store computed results
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    // Initialize 'front' for the last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += front[j1 + di][j2 + dj]; // Include the value from the 'front' array

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                cur[j1][j2] = maxi; // Store the maximum result for this state in the 'cur' array
            }
        }
        front = cur; // Update 'front' with the values from 'cur' for the next iteration
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the 'front' array
    return front[0][m - 1];
}