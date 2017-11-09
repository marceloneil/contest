#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int prefixSum[405], arr[405], dp[405][405];//,size[405][405];
int f(int i,int j){
  if(dp[i][j] != -1) return dp[i][j];
  if(i>=j){
    dp[i][j] = 1;
    return 1;
  }
  if(j-i == 1){
    if(arr[i] == arr[j]){
      dp[i][j] = 1;
      return 1;
    }else{
      dp[i][j] = 0;
      return 0;
    }
  }
  if(j-i == 2){
    if(arr[i] == arr[j]){
      dp[i][j] = 1;
      return 1;
    }else{
      dp[i][j] = 0;
      return 0;
    }
  }

  for(int a = i; a < j;a++){
    if(f(i,a) * f(a+1,j)){
      dp[i][j] = 1;
      return 1;
    }
  }

  //here I am attempting to do the i,a a,b b,j but it'll add another n^2
  //ik there is a way to keep it at n 
  /*
  for(int x = i; x <=j;x++){
    for(int y = x; y <=j;y++){
      if()
    }
  }*/
  /*
int b = j-1;
  for(int a = i+1;a<j;a++){
    if(f(i,a) * f(a+1,b-1) * f(b,j)){
      dp[i][j] = 1;
      return 1;
    }
    j--;
  }*/
  dp[i][j] = 0;
  return 0;
}

int main(){
  int n,maxAns;
  maxAns = 0;
  scanf("%d",&n);
  for(int i = 1;i<=n;i++){
    int temp;
    scanf("%d",&temp);
    arr[i] = temp;
    prefixSum[i] = prefixSum[i-1] + temp;
  }
  memset(dp,-1,sizeof dp);
  for(int i = 1; i <=n;i++){
    for(int j = i; j <=n;j++){
      cout<<f(i,j)<<endl<<i<<endl<<j<<endl<<endl;
      if(f(i,j)){
        maxAns = max(maxAns, prefixSum[j] - prefixSum[i-1]);
      }
    }
  }
  cout<<maxAns<<endl;
}
