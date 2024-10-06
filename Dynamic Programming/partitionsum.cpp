#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        if(sum & 1) return false;
        else{
            int k = sum/2;
            vector<bool> prev(k+1, 0), curr(k+1, 0);
            prev[0] = curr[0] = true;
            if (nums[0] <= k)
                prev[nums[0]] = true;

            for(int ind=1; ind<nums.size(); ind++){
                for(int target=1; target<=k; target++){
                    bool notTake = prev[target];
                    bool take = false;
                    if(nums[ind] <= target) take = prev[target - nums[ind]];
                    curr[target] = (take || notTake);
                }
                prev = curr;
            }
            return prev[k];
        }
        
    }
};