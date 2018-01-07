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

int p,r;
int dp[103][13];

int calc(int s, int n){
  if(dp[s][n] != -1) return dp[s][n];
  if(!s){
    dp[s][n] = 1;
    return 1;
  }
  if(s!= 0 && !n){
    dp[s][n] = 0;
    return 0;
  }
  int ans = 0;
  for(int i = 0;i<=s;i++){
    ans+= calc(s-i,n-1);
  }
  dp[s][n] = ans;
  return ans;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(dp,-1,sizeof dp);

  cin>>p>>r;
  cout<<calc(r,p)<<endl;
}
