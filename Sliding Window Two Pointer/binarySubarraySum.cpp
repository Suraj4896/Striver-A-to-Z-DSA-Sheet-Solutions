#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l = 0, r = 0,  cnt = 0;
        long long int sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = solve(nums, goal) - solve(nums, goal-1);
        return ans;
    }
};