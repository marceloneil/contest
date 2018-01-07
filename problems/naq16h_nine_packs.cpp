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

int h,b;
int hh[103],bb[103];
int dp[103][103];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>h>>b;
  for(int i = 1; i<=h;i++){
    cin>>hh[i];
  }
  for(int i = 1; i <=b;i++){
    cin>>bb[i];
  }
}
int N,C;
//get input
for (int i = 1; i <= N; i++){

  for (int j = 0; j <= C; j++){

    if (j < weight[i]) dp[i][j] = dp[i-1][j];
    else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);

  }

}
print dp[N][C];
