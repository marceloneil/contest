#include <iostream>
using namespace std;
long long dp[100005];
int main(){
  string g;
  cin>>g;
  for(int i = 1; (unsigned)i <= g.size();i++){
    if( g.at(i-1) == 'G'){
      dp[i] = dp[i-1] + 1;
    }else{
      dp[i] = dp[i-1];
    }
  }
  int q;
  cin>>q;
  while(q--){
    int temp1,temp2;
    cin>>temp1>>temp2;
    cout<<dp[temp2 + 2] - dp[temp1];
  }
}
