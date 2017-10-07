
#include <iostream>


using namespace std;
int dp[3];

int main(){
  int n;
  string str;
  cin>>n>>str;
  for(int i = 0; i < n;i++){
    int val = str.at(i);
    if(val == '~'){
      int tMin = min(dp[0],min(dp[1],dp[2]));
      if(dp[0] == tMin){
        dp[0] = dp[0] + 1;
      }
      if(dp[1] == tMin){
        dp[1] = dp[1] + 1;
      }
      if(dp[2] == tMin){
        dp[2] = dp[2] + 1;
      }
    }else{
      dp[val-49] = dp[val-49] + 1;
    }
  }
  int tMin = min(dp[0],min(dp[1],dp[2]));
  if(dp[0] == tMin){
    cout<<"1"<<endl;
  }
  if(dp[1] == tMin){
    cout<<"2"<<endl;
  }
  if(dp[2] == tMin){
    cout<<"3"<<endl;
  }
}
