#include <bits/stdc++.h> 
using namespace std;

//recursion
int solve(int ind, int w, vector<int>& wt, vector<int>& val){
	if(ind == 0){
		if(wt[0] <= w) return val[0];
		else return 0;
	}

	int notTake = 0 + solve(ind-1, w, wt, val);
	int take = INT_MIN;
	if(wt[ind] <= w) take = val[ind] + solve(ind-1, w-wt[ind], wt, val);

	return max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(n-1, maxWeight, weight, value);
}

//memoization
int solve(int ind, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
	if(ind == 0){
		if(wt[0] <= w) return val[0];
		else return 0;
	}

	if(dp[ind][w] != -1) return dp[ind][w];

	int notTake = 0 + solve(ind-1, w, wt, val, dp);
	int take = INT_MIN;
	if(wt[ind] <= w) take = val[ind] + solve(ind-1, w-wt[ind], wt, val, dp);

	return dp[ind][w] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(n-1, maxWeight, weight, value, dp);
}

//tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	for(int i=weight[0]; i<=maxWeight; i++){
		dp[0][i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int w=0; w<=maxWeight; w++){
			int notTake = 0 + dp[i-1][w];
			int take = INT_MIN;
			if(weight[i] <= w) take = value[i] + dp[i-1][w-weight[i]];
			dp[i][w] = max(take, notTake);
		}
	}
	return dp[n-1][maxWeight];
	
}

//space optimisation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

	for(int i=weight[0]; i<=maxWeight; i++){
		prev[i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int w=0; w<=maxWeight; w++){
			int notTake = 0 + prev[w];
			int take = INT_MIN;
			if(weight[i] <= w) take = value[i] + prev[w-weight[i]];
			curr[w] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[maxWeight];
	
}