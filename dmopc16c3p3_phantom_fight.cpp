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

int n,m,c;
int val[10004], weight[10004];
int dp[2][10004];


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>c;
  for(int i= 1;i<=n;i++){
    cin>>weight[i]>>val[i];
  }
  memset(dp,-1,sizeof dp);
  int cur = 0;
  dp[0][c] = 0;

}
