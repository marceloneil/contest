//crap I really need to fix this
#include <iostream>
#include <climits> // INT_MAX
#include <cstring> // memset
using namespace std;
int dp[5283][34];
int main(){
  int d,n;
  cin>>d;
  cin>>n;
  int arr[32];
  for(int i = 1; i <= n; i++){
    cin>>arr[i];
  }
  memset(dp,0x3f3f3f3f,sizeof dp);
  dp[1][0] = 0;
  for(int i = 0; i < 34; i++){
    dp[0][i] = 0;
  }
  for (int j=1; j<=d; j++){
    for (int i=1; i<=n; i++){
      if(j - arr[i] >= 0){
        //1 = don't use this putt, 2 = use this putt
        dp[j][i] = min(dp[j][i-1], dp[j-arr[i]][i] + 1);
      }
    }
  }
  if(dp[d][n] != 0x3f3f3f3f){
    cout<<"Roberta wins in "+ to_string(dp[d-1][n-1]) +" strokes."<<endl;
  }else{
    cout<<"Roberta acknowledges defeat."<<endl;
  }
}
