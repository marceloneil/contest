#include <iostream>
using namespace std;
int n,x,y,z;
int dp[100005];
int main(){
  cin>>n;
  cin>>x>>y>>z;
  dp[x] = 1;
  dp[y] = 1;
  dp[z] = 1;
  for(int i =0; i <= n;i++){
    if(i + x <= n){
        dp[i + x] = max(dp[i + x],dp[i] + 1);
    }
    if(i + y <= n){
        dp[i + y] =  max(dp[i + y],dp[i] + 1);
    }
    if(i + z <= n){
        dp[i + z] = max(dp[i + z],dp[i] + 1);
    }
  }
  cout<<dp[n]<<endl;
}
