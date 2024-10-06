#include <bits/stdc++.h> 
using namespace std;


//space optimisation
class Solution {
public:
    int findMaxMoney(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        int ans1 = findMaxMoney(temp1);
        int ans2 = findMaxMoney(temp2);

        return max(ans1,ans2);
    }
};