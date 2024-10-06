#include <bits/stdc++.h> 
using namespace std;

//memoization

int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            else return 0;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = solve(ind-1, amount, coins, dp);
        int take = 0;
        if(coins[ind] <= amount) take = solve(ind, amount-coins[ind], coins, dp);

        return dp[ind][amount] = take+notTake;
}

//tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = 1;
        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0) dp[0][T] = 1;
        }
        for(int i=1; i<n; i++){
            for(int T=0; T<=amount; T++){
                int notTake = dp[i-1][T];
                int take = 0;
                if(coins[i] <= T) take = dp[i][T-coins[i]];
                dp[i][T] = take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};

//space optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int i=0; i<n; i++) prev[0] = 1;
        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0) prev[T] = 1;
        }
        for(int i=1; i<n; i++){
            for(int T=0; T<=amount; T++){
                int notTake = prev[T];
                int take = 0;
                if(coins[i] <= T) take = curr[T-coins[i]];
                curr[T] = take+notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};