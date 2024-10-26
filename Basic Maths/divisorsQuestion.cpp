#include <bits/stdc++.h> 
using namespace std;
class Solution {
  public:
    vector<long long> divisors(int num){
        vector<long long> ans;
        for(int i=1; i<=sqrt(num); i++){
            if(num % i == 0){
                ans.push_back(i);
                if(num/i != i) ans.push_back(num/i);
            }
        }
        return ans;
    }
    long long sumOfDivisors(int n) {
        long long totalSum = 0;
        for(int i=1; i<=n; i++){
            long long divSum = 0;
            vector<long long> div = divisors(i);
            for(auto it : div) divSum += it;
            totalSum += divSum;
        }
        return totalSum;
    }
};
