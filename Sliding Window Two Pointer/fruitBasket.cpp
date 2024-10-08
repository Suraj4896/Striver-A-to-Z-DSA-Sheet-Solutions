#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int, int> mp;
        while(r < fruits.size()){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            else maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};