#include <bits/stdc++.h> 
using namespace std;

//recursion
int houseRobber(int ind, vector<int>& nums){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    int pick = nums[ind] + houseRobber(ind - 2, nums);
    int notPick = 0 + houseRobber(ind - 1, nums);

    return max(pick, notPick);
}
int hrob(vector<int> nums){
    int n = nums.size();
    houseRobber(n-1, nums);
}

//memoization
int houseRobber(int ind, vector<int>& nums, vector<int>& dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + houseRobber(ind - 2, nums, dp);
    int notPick = 0 + houseRobber(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}
int hrob(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    houseRobber(n-1, nums, dp);
}

//tabulation
int houseRobber(vector<int>& nums, vector<int>& dp, int n){
    dp[0] = nums[0];
    int neg = 0;

    for(int i=1; i<n; i++){
        int pick = nums[i] + (i > 1 ? dp[i-2] : neg);
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick, notPick);
    }

    return dp[n-1]; 
}
int hrob(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    houseRobber(nums, dp, n);
}

//space optimisation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prevHome = nums[0];
        int prevHome2 = 0;

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1)
                pick += prevHome2;
            int notPick = 0 + prevHome;
            int curr = max(pick, notPick);
            prevHome2 = prevHome;
            prevHome = curr;
        }
        return prevHome;
    }
};