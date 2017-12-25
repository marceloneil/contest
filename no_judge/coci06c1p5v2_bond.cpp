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

int fullMask; // if an index in mask =1 that means that it has already been assigned
int arr[23][23];
ll dp[1048577][23];
int n;
int calc(int mask, int curBond){
  if(dp[mask][curBond] != -1) return dp[mask][curBond];
  if(mask == fullMask) return 1;
  int maxCur = -INF;
  for(int i = 0;i<n;i++){
    if(!(mask & (1<<i))){
      maxCur = max(maxCur, calc(mask | (1<<i),curBond+1) * arr[i][curBond]);
    }
  }
  return dp[mask][curBond] = maxCur;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  fullMask = (1<<n)-1;
  for(int i = 0; i<n;i++){
    for(int a = 1; a<=n;a++){
      cin>>arr[i][a];
  }
}
memset(dp,-1,sizeof dp);
  printf("%f",calc(0,1)*100/(pow(100,n)));
}
