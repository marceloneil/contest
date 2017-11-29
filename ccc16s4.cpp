//okay the code segment faults. I think when I'm checking the sub ranges I somehow glitch a range that is either greater or the same size. That way it'll never solve it.

#include <bits/stdc++.h>
using namespace std;

#define MAXN 403
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ll long long
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

ll n,arr[MAXN],dp[MAXN][MAXN];
ll maxSize = 0;
int theCount = 0;
int solve(int l, int r){
  //cout<<l<<" "<<r<<endl;
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r){
    dp[l][r] = arr[l];
    maxSize = max(maxSize, dp[l][r]);
    return dp[l][r];
  }
  if(r-l == 1){
    if(arr[r] == arr[l]){
      dp[l][r] = arr[r]*2;
      maxSize = max(maxSize, dp[l][r]);
      return dp[l][r];
    }
  }
  if(r-l == 2){
    if(arr[l] == arr[r]){
      dp[l][r] = arr[r] + arr[l] + arr[l+1];
      maxSize = max(maxSize, dp[l][r]);
      return dp[l][r];
    }
  }
  if(r-l > 2){
    for(int i = 1; l + i <=r;i++){
      int ans1 = solve(l,l+i-1);
      if((ans1 != 0) && ans1 == solve(l+i,r)){
        dp[l][r] = ans1*2;
        maxSize = max(maxSize, dp[l][r]);
        return dp[l][r];
      }
    }


    for(int s = 1; s <=(r-l);s++){
      for(int a = 1; l + a + s<=r;a++){
        int ans1 = solve(l,l+a-1);
        int ans2 = solve(l+a,l+a+s-1);
        int ans3 = solve(l+a+s,r);
        if((ans1 != 0) && (ans1 == ans3) && ans2 > 0){
          dp[l][r] = ans1 + ans2 + ans3;
          maxSize = max(maxSize, dp[l][r]);
          return dp[l][r];
        }
      }
    }
  }
  dp[l][r] = 0;
  return 0;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1 , sizeof dp);
  cin>>n;
  for(int i = 1;i<=n;i++){
    cin>>arr[i];
  }
  solve(1,n);
/*
  for(int i = 1; i <=n;i++){
    for(int a = 1; a <=n;a++){
      maxSize = max(maxSize,dp[i][a]);
    }
  }*/
  cout<<maxSize<<endl;
}
