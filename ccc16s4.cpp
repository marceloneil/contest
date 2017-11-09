#include <bits/stdc++.h>
using namespace std;

#define MAXN 405
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int n,arr[MAXN],dp[MAXN][MAXN],ballCount[MAXN][MAXN];
int main(){
  for(int i = 1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  for(int i = 1; i <= n;i++){
    for(int a = 1;a<=n;a++){
      dp[i][a]
    }
  }
  if(dp[l][l] == dp[r][r] && ballCount[l+1][r-1]){
    //I need some sort of count array to keep tract of the numver of riceballs within a range.
    if(dp[l][l] + dp[l+1][r-1] + dp[r][r] > dp[l][r]){
      dp[l][r] = dp[l][l] + dp[l+1][r-1] + dp[r][r];
      ballCount[l][r] = 1;
    }
  }
  if(dp[l][r-1] == dp[r][r]){
    dp[l][r] = max(dp[l][r], dp[l][r-1] + dp[r][r]);
  }
  printf("%d", dp[1][n]);
}
