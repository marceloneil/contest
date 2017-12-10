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

int dist[100005];
int dp[100005][100005]; // the side that a cop car ends at

  int n, h;
int calc(int a, int b){
  if(dp[a][b] != INF) return dp[a][b];
  if(a == b){
    dp[a][b] = h;
    dp[b][a] = h;
    return dp[b][a];
  }
  if(a > b){
    dp[a][b] = 
  }else{

  }

}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(dp,INF, sizeof dp);
  cin>>n>>h;
  for(int i = 1; i <=n;i++){
    cin>>dist[i];
  }

}
