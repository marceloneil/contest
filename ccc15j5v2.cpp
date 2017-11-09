#include <bits/stdc++.h>
using namespace std;

#define MAXN 255
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


int dp[MAXN][MAXN];
int calc(int n,int k){
  if(n < k){
    return 0;
  }
  if(n == k || k == 1){
    return 1;
  }
  if(dp[n][k] != -1){ // memoization
    return dp[n][k];
  }
  dp[n][k] = calc(n-1,k-1) + calc(n-k,k);
  return dp[n][k];
}
int main(){
  memset(dp, -1, sizeof dp);
  int a,b;
  scanf("%d %d", &a,&b);
  printf("%d", calc(a,b));
}
