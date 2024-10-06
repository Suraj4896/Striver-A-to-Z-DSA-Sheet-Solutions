#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        int ans = INT_MAX;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[start] <= nums[mid]){
                //if left half is sorted
                ans = min(ans,nums[start]);
                start = mid+1;
            }
            else{
                //if right half is sorted
                ans = min(ans,nums[mid]);
                end = mid-1;
            }
        }
        return ans;
        
    }
};