#include<bits/stdc++.h>
using namespace std;

int fibonnacci(int n, vector<int> &dp){
    //base case
    if(n <= 1) return n;

    //check that the value of each call is stored in the dp array or not
    if(dp[n] != -1) return dp[n];

    //recurssion
    return dp[n] = fibonnacci(n-1,dp) + fibonnacci(n-2,dp);
}

int main() {

  int n=5;
  vector<int> dp(n+1,-1);  //declaration of DP array with size n+1
  cout << fibonnacci(n,dp);



  //Tabulation
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];


  //space optimization
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}