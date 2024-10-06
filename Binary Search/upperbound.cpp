#include<bits/stdc++.h>
using namespace std;

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