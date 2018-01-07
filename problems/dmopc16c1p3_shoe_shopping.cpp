#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
double arr[10005], dp[10005];
int main(){
  int n;
  cin >> n;
  for(int i = 1 ; i <= n;i++){
    cin>>arr[i];
  }
  memset(dp,0x3f3f3f3f,sizeof dp);
  dp[0] = 0;
  for(int i = 1; i <=n;i++){
    dp[i] = dp[i -1] + arr[i];
    if(i > 1){
      dp[i] = min(dp[i], dp[i-2] + arr[i-1] + arr[i] - (min(arr[i-1], arr[i])/2));
    }
    if(i>2){
      dp[i] = min(dp[i], dp[i-3] + arr[i-2] + arr[i-1] + arr[i] - min(arr[i-2],min(arr[i-1], arr[i])));
    }
  }
  printf("%.1f", floor(dp[n] * 10.0 + 0.5) / 10.0);
}
