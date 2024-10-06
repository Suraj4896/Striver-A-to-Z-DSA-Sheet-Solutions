#include <bits/stdc++.h> 
using namespace std;


//recursion
class Solution{
public:
    int solve(int ind, int w, int wt[], int val[]){
	    if(ind == 0){
		    return (w/wt[0])*val[0];
	    }

	    int notTake = 0 + solve(ind-1, w, wt, val);
	    int take = INT_MIN;
	    if(wt[ind] <= w) take = val[ind] + solve(ind, w-wt[ind], wt, val);

	    return max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(N-1, W, wt, val);
    }
};

//memoization
class Solution{
public:
    int solve(int ind, int w, int wt[], int val[], vector<vector<int>>& dp){
	    if(ind == 0){
		    return (w/wt[0])*val[0];
	    }
	    
	    if(dp[ind][w] != -1) return dp[ind][w];

	    int notTake = 0 + solve(ind-1, w, wt, val, dp);
	    int take = INT_MIN;
	    if(wt[ind] <= w) take = val[ind] + solve(ind, w-wt[ind], wt, val, dp);

	    return dp[ind][w] = max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        return solve(N-1, W, wt, val, dp);
    }
};

//tabulisation
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}

//space optimisation
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> cur(W + 1, 0); // Create a vector to store the current DP state

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = cur[cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]]; // Maximum value by taking the current item

            cur[cap] = max(notTaken, taken); // Store the maximum value in the current DP state
        }
    }

    return cur[W]; // Return the maximum value considering all items and the knapsack capacity
}

