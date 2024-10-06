#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> arr, int n, int target){
        int start = 0;
        int end = n-1;
        int ans = n;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] >= target){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    int upperBound(vector<int> arr, int n, int target){
        int start = 0;
        int end = n-1;
        int ans = n;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] > target){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int lb = lowerBound(nums,n,target);
        if(lb == n || nums[lb] != target){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(lb);
            ans.push_back(upperBound(nums,n,target)-1);
        }
        return ans;
    }
};