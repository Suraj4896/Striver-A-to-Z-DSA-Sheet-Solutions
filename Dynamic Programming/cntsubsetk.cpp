#include <bits/stdc++.h> 
using namespace std;

//recursion
int solve(int ind, int target, vector<int> &arr){
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target) ? 1 : 0;

    int notTake = solve(ind-1, target, arr);
    int take = 0;
    if(arr[ind] <= target) take = solve(ind-1, target-arr[ind], arr);

    return (take + notTake);
}
int subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1, k, arr);
}

//memoization
int solve(int ind, int target, vector<int> &arr, vector<vector<int>>& dp){
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target) ? 1 : 0;

    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve(ind-1, target, arr, dp);
    int take = 0;
    if(arr[ind] <= target) take = solve(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = (take + notTake);
}
int subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}

//tabulation
int subsetSumToK(int k, vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<bool>(k+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;

    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=k; target++){
            bool notTake = dp[ind-1][target];
            bool take = 0;
            if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
            dp[ind][target] = (take + notTake);
        }
    }
    return dp[n-1][k];
}

//space optimisation
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);
        for(int i=0; i<n; i++) prev[0] = 1, curr[0] = 1;
        if (arr[0] <= k)
            prev[arr[0]] = 1;

        for(int ind=1; ind<n; ind++){
            for(int target=1; target<=k; target++){
                int notTake = prev[target];
                int take = 0;
                if(arr[ind] <= target) take = prev[target - arr[ind]];
                curr[target] = (take + notTake);
            }
            prev = curr;
        }   
        return prev[k];
}
