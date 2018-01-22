//literally 0-1 knapsack.
#include <iostream>
#include <cstring>
using namespace std;
int dp[5005][10005], ghosts[5005],energy[5005];
int main(){
  memset(dp,-1,sizeof dp);
  int n,m;
  cin>>n>>m;
  for(int i = 1; i <= n;i++){
    cin>>ghosts[i]>>energy[i];
  }
  /*for(int i = 1; i <= n;i++){
    for(int j = 1; j <= m;j++){
      if(j - ghosts[i] >= 0){
        int valOfWin = j - ghosts[i] + energy[i];
        dp[i][j] = max(dp[i-1][j-energy[i]] + 1, dp[i-1][j-energy[i]]);
      }
    }
  }*/
  for (int i = 1; i <= n; i++){

    for (int j = 0; j <= m; j++){

      if (j < weight[i]){
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);
      }
    }

  }
  cout<<dp[n][m]<<endl;
}
