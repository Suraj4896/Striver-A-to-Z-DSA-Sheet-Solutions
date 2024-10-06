#include<bits/stdc++.h>
using namespace std;



int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = n;
        // int finalAns = searchIndex(nums,target,start,end,n);
        // return finalAns;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] >= target){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
        
}