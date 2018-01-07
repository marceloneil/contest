#include <bits/stdc++.h>
using namespace std;
int n,arr[4][100003],dp[5][100003];
int main(){
  scanf("%d",&n);
  for(int i = 1; i <= n;i++){
    scanf("%d %d %d %d",&arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]);
  }
  for(int a = 1 ; a <= 4; a++){
    for(int i = 1; i <= n;i++){
      //dp[a][i] = max(dp[a][i-1],arr[a][i]);
      dp[a][i] = max(dp[a-1][i], arr[a][i]);
    }
  }
  printf("%d",dp[3][n]);
}
