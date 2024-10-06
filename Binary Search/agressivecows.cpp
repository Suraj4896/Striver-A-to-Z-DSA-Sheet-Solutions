#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stall, int dist, int cows){
    int cntCows = 1, last = stall[0];

    for(int i=0; i<stall.size(); i++){
        if(stall[i] - last >= dist){
            cntCows++, last = stall[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int agressiveCows(vector<int> &stall, int k){
    sort(stall.begin(), stall.end());
    int n = stall.size();
    int low = 1, high = stall[n-1] - stall[0];

    while(low <= high){
        int mid = (low + high)/2;
        if(canWePlace(stall,mid,k)) low = mid+1;
        else high = mid-1;
    }
    return high;
}