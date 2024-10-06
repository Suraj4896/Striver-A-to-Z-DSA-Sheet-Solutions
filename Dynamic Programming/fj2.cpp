#include <bits/stdc++.h> 
using namespace std;

//tabulation

int frogJump2(int n, vector<int> &height, int k){
    vector<int> dp(n, -1);

    dp[0] = 0;

    for(int i=1; i<n; i++){
        int minEnergy = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0){
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                minEnergy = min(minEnergy,jump);
            }
        }
        dp[i] = minEnergy;
    }

    return dp[n-1];
}

//space optimization(no need of space optimization as if k == n then it becomes again O(n))