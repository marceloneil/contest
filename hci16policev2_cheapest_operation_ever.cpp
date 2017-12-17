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
ll dp[100005];
ll n,h;

ll f(int a, int b){
  return pow(b-a,2);
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>h;
  //memset(dp,, sizeof dp);
  for(int i = 1; i <=n;i++){
    cin>>dist[i];
  }
  for(int i = 1; i <=n;i++){
    dp[i] = dp[i-1] + h;
    for(int a = 1;a <i;a++){
      dp[i] = min(dp[i], dp[i-a] +f(dist[i-a+1],dist[i]) + h);
    }
  }
  cout<<dp[n]<<endl;
}
