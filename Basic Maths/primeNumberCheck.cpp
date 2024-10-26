#include <bits/stdc++.h> 
using namespace std;

//tle
class Solution {
public:
    bool checkPrime(int num){
        int cntDiv = 0;
        for(int i=1; i*i<=num; i++){
            if(num % i == 0){
                cntDiv++;
                if(num/i != i) cntDiv++;
            }
        }
        return cntDiv == 2;
    }
    int countPrimes(int n) {
        int count = 0;
        for(int i=1; i<n; i++){
            if(checkPrime(i)) count++;
        }
        return count;
    }
}; 

//optimised ( Sieve of Eratosthenes algorithm)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i < n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        int cntPrime = 0;
        for(int i=2; i<n; i++){
            if(isPrime[i]) cntPrime++;
        }
        return cntPrime;
    }
};