#include<bits/stdc++.h>
using namespace std;

//extra space
class Solution {
public:
    void permutation(vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums, vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(freq[i] != 1){
                ds.push_back(nums[i]);
                freq[i] = 1;
                permutation(ans, ds, nums, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        permutation(ans, ds, nums, freq);
        return ans;
    }
};


//swap
class Solution {
public:
    void permutation(int ind, vector<int>& nums, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            permutation(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(0, nums, ans);
        return ans;
    }
};