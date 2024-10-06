#include <bits/stdc++.h> 
using namespace std;

//recursion
class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins){
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else return INT_MAX;
        }

        int notTake = 0 + solve(ind-1, amount, coins);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + solve(ind, amount-coins[ind], coins);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 1 && coins[0] < amount) return -1;
        return solve(n-1, amount, coins);
    }
};

//memoization
class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else return INT_MAX;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = 0 + solve(ind-1, amount, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + solve(ind, amount-coins[ind], coins, dp);

        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 1 && coins[0] < amount) return -1;
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};

//tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 1 && amount%coins[0]) return -1;
        int cnt = 0;
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0) dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int target=0; target<=amount; target++){
                int notTake = 0 + dp[i-1][target];
                int take = 1e9;
                if(coins[i] <= target) take = 1 + dp[i][target-coins[i]];
                dp[i][target] = min(take, notTake);
            }
        }
        return (dp[n-1][amount] >= 1e9) ? -1 : dp[n-1][amount];
    }
};

//space optimisation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 1 && amount%coins[0]) return -1;
        int cnt = 0;
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0) prev[T] = T/coins[0];
            else prev[T] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int target=0; target<=amount; target++){
                int notTake = 0 + prev[target];
                int take = 1e9;
                if(coins[i] <= target) take = 1 + curr[target-coins[i]];
                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        return (prev[amount] >= 1e9) ? -1 : prev[amount];
    }
};