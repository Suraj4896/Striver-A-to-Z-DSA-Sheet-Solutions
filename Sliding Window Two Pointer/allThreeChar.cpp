#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastSeen(3, -1);
        int cnt = 0;
        for(int i=0; i<n; i++){
            lastSeen[s[i]-'a'] = i;
            cnt += 1 + min(lastSeen[0],min(lastSeen[1], lastSeen[2]));
        }
        return cnt;
    }
};