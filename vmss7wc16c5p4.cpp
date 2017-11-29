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

int n,x,y,z;
int dp[100005];

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cin>>x>>y>>z;
  dp[x] = 1;
  dp[y] = 1;
  dp[z] = 1;
  for(int i =min(x,min(y,z)); i <= n;i++){
    if(i + x <= n){
      if(dp[i] > 0){
        dp[i + x] = max(dp[i + x],dp[i] + 1);
      }
    }
    if(i + y <= n){
      if(dp[i] > 0){
        dp[i + y] =  max(dp[i + y],dp[i] + 1);
      }
    }
    if(i + z <= n){
      if(dp[i] > 0){
        dp[i + z] = max(dp[i + z],dp[i] + 1);
      }
    }
  }
  cout<<dp[n]<<endl;
}
