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

int vals[4][100005];
int dp[4][100005];
int n;
void calc(){
  memset(dp, -1, sizeof dp);
  for(int i = 0; i <4;i++){
    for(int a = 1; a<=n;a++){
      dp[i][a] = max(dp[i][a-1], dp[i-1][a] + vals[i][a]);
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>vals[0][i]>>vals[1][i]>>vals[2][i]>>vals[3][i];
  }
  calc();
  cout<<dp[3][n];
}
