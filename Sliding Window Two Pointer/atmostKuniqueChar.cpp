#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int l = 0, r = 0, maxLen = -1;
        unordered_map<char, int> mp;
        while(r < s.length()){
            mp[s[r]]++;
            if(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if(mp.size() == k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};