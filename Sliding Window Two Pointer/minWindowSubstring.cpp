#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for(char c : t) {
            freq[c]++;
        }

        int l = 0, r = 0, minLen = INT_MAX, si = -1, cnt = 0;

        while(r < s.size()) {
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;

            while(cnt == t.size()) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    si = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return si == -1 ? "" : s.substr(si, minLen);
    }
};