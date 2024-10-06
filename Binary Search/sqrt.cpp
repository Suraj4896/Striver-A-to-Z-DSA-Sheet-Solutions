
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int low = 1;
        long long int high = x;
        
        while(low <= high){
           long long int mid = low + (high - low)/2;
           long long int val = mid*mid;
           
           if(val <= x) low = mid+1;
           else high = mid-1;
        }
        return high;
    }
};