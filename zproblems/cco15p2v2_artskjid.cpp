#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
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

vector<PII> edges[21]; // nextnode, weight of edge

int n,m;

int fullMask;
int dp[262147][21];

int calc(int mask, int city){
  if(city == n) return 0;
  if(dp[mask][city] != -1) return dp[mask][city];
  int maxd = 0;
  for(PII a : edges[city]){
    if((mask & (1<<a.F)) == 0){ // I haven't visited this city yet
      maxd = max(maxd, a.S + calc(mask | (1<<a.F), a.F));
    }
  }
  return dp[mask][city] = maxd;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  fullMask = (1<<n)-1;
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a+1].PB({b+1,c});
  }
  memset(dp,-1,sizeof dp);
  cout<<calc(1,1)<<endl;
}
