//what the heck is this messed up question
#include <iostream>
using namespace std;
#define MAXN 2000
#define MAXT 10000
int dp[MAXT][MAXT];
int main(){
  int N,C;
  cin>>N>>C;
  int val[MAXN],weight[MAXT];
  for(int i = 0,pp,pv,pa,va,pg,vg ; i < N ; i++){
    cin>>pp>>pv>>pa>>va>>pg>>vg;
    val[i*3] = pv;
    val[(i*3)+1] = va;
    val[(i*3)+2] = vg;
    weight[i*3] = pp;
    weight[(i*3)+1] = pa;
    weight[(i*3)+2] = pg;
  }
  //get input

  //fill DP array
  //get input
  for (int i = 1; i <= N; i++){
    for (int j = 0; j <= C; j++){
      if (j < weight[i]){
        cout<<weight[i]<<endl;
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);
      }
    }
  }
  cout<<dp[N][C];
  /*
  for (int i = 0; i <= N; i++){
  for (int j = T; j >= weight[i]; j--){
  dp[j] = max(dp[j],dp[j-weight[i]] + val[i]);
  //cout<<dp[j]<<endl;
  cout<<j<<endl;
}
}
cout<<dp[T]<<endl;*/
}
