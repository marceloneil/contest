#include <bits/stdc++.h>
using namespace std;
int c,n;
int weight[1003], val[1003];
int dp[1003];

//get input
void knapsack(){
  memset(dp,-1,sizeof dp);
  for (int i = 1; i <= n; i++){
    for (int j = c; j >= weight[i]; j--){
      dp[j] = max(dp[j],dp[j-weight[i]] + val[i]);
    }
  }
  cout<<dp[c]<<endl;
}
