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

vector<PII> edges[20]; // nextnode, weight of edge

int n,m;

int fullMask;
int dp[1048576][20];

int calc(int mask, int city){
  if(city == n-1) return dp[mask][city] = 0;
  if(dp[mask][city] != -1) return dp[mask][city];
  if(mask == fullMask) return dp[mask][city] = -INF;
  int maxd = -INF;
  for(PII a : edges[city]){
    //if(a.F != 0){ // there is no mask for the 0th city. so this case is to check for it
      if(((mask & (1<<a.F)) == 0)){ // I haven't visited this city yet
        int temp = calc(mask | (1<<a.F), a.F);
        if(temp != -INF) maxd = max(maxd, temp + a.S);
      }
    //}
  }
  return dp[mask][city] = maxd;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  fullMask = (1<<n)-1;
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
  }
  memset(dp,-1,sizeof dp);
  cout<<calc(1,0)<<endl;
}
