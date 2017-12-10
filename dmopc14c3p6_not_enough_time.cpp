#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
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

int cost[3][2003], val[3][2003], dp[2003][10005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,t;
  cin>>n>>t;
  for(int i = 1; i<=n;i++){
    cin>>cost[2][i]>>val[2][i]>>cost[1][i]>>val[1][i]>>cost[0][i]>>val[0][i];
  }

  memset(dp,-1,sizeof dp);
  dp[0][0] = 0;
  dp[0][1] = 0;
  for(int i = 1; i <=n;i++){
    for(int a = 1; a <=t; a++){
      if(a - cost[0][i] > 0){
        dp[i][a] = max(dp[i][a-1], dp[i-1][a-cost[0][i]] + val[0][i]);
      }
      if(a - cost[1][i] > 0){
        dp[i][a] = max(dp[i][a],max(dp[i][a-1], dp[i-1][a-cost[1][i]] + val[1][i]));
      }
      if(a - cost[2][i] > 0){
        dp[i][a] = max(dp[i][a],max(dp[i][a-1], dp[i-1][a-cost[2][i]] + val[2][i]));
      }
    }
  }
  cout<<dp[n][t]<<endl;

}
