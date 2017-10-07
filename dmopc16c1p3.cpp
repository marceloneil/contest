#include <iostream>
#include <cstring>
using namespace std;
double arr[10005], dp[10005];
int main(){
  int n;
  cin >> n;
  for(int i = 0 ; i < n;i++){
    cin>>arr[i];
  }
  memset(dp,0x3f3f3f3f,sizeof dp);
  for(int i = 1; i <=n;i++){
    dp[i] = dp[i -1] + arr[i];
    if(i > 2){
      dp[i] = dp[i-2] + arr[i-1] + arr[i] - min(arr[i],arr[i-1])/2.0;
    }
    if(i>3){
      dp[i] = dp[i-3] + arr[i-2] + arr[i-1] + arr[i] - min(arr[i],min(arr[i-1], arr[i-2]));
    } 
  }
  cout<<dp[n]<<endl;
}
