#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findWays(int k, vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
    
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=k; target++){
                int notTake = dp[ind-1][target];
                int take = 0;
                if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
                dp[ind][target] = (take + notTake);
            }
        }
        return dp[n-1][k];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(int i=0; i<arr.size(); i++) totalSum += arr[i];
        if(totalSum-d < 0 || (totalSum-d)%2) return 0;
        return findWays((totalSum-d)/2, arr);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};