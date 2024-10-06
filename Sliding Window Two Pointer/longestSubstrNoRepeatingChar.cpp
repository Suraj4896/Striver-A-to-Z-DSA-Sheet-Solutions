#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> hash(256, -1);
        int L = 0, R = 0;
        int maxLen = 0;
        while(R < n){
            if(hash[s[R]] != -1){
                if(hash[s[R]] >= L) L = hash[s[R]] + 1;
            }
            maxLen = max(maxLen, R-L+1);
            hash[s[R]] = R;
            R++;
        }
        return maxLen;
    }
};