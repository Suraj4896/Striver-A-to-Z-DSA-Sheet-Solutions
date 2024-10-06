#include <bits/stdc++.h> 
using namespace std;

int energy(int n, vector<int> &heights, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int energy1 = energy(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int energy2 = INT_MAX;
    if(n > 1) energy2 = energy(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
        
    return dp[n] = min(energy1, energy2);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return energy(n-1,heights,dp);
}



//tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int energy1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int energy2 = INT_MAX;
        if(i > 1){
             energy2 = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(energy1, energy2); 
    }
    return dp[n-1];
}



//space optimization
#include <bits/stdc++.h> 


int frogJump(int n, vector<int> &heights)
{
    
    int prev1 = 0;
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int energy1 = prev1 + abs(heights[i] - heights[i-1]);
        int energy2 = INT_MAX;
        if(i > 1){
             energy2 = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr = min(energy1, energy2); 
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}