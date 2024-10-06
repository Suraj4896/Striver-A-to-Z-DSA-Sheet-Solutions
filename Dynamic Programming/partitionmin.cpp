#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int s = 0;
    for(int i=0; i<n; i++) s += arr[i];
    vector<vector<bool>> dp(n, vector<bool>(s+1, false));
    for(int i=0; i<n; i++) dp[i][0] = true;
        if (arr[0] <= s)
            dp[0][s] = true;

        for(int ind=1; ind<n; ind++){
            for(int target=1; target<=s; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
                dp[ind][target] = (take || notTake);
            }
        }
        int s1 = 0, s2 = 0, minAns = 1e9;
        for(int i=0; i<=s; i++){
            if(dp[n-1][i]){
                s1 = i;
                s2 = s - i;
                minAns = min(minAns, abs(s1-s2));
            }
        }
        return minAns;
}
