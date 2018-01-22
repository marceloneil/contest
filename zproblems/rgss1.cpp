#include <iostream>
using namespace std;
int dp[1005];
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  dp[0] = 1;
  for(int i = 0; i < c;i++){
    if(dp[i] != 0){//there is a way to fill up the bottle to this capacity
      if(i + b<= c){
        dp[i + b] = 1;
      }
      if(i + a <= c){
        dp[i+a] = 1;
      }
    }
  }
  for(int i = c; i >= 0;i--){
    if(dp[i] != 0){
      cout<<i<<endl;
      return 0;
    }
  }
}
