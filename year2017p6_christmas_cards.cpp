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

int dp[5005];
int cards[5005];
int cost[5005];
void seeCheaper(int a){
  if(cards[a] == 0){
    return;
  }
  if(cost[a] == 0){

  }
  for(int i = 1; i <=cards[a];i++){
    dp[a + i] = min(dp[a + i],dp[a] + cost[a]);
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>cost[i]>>cards[i];
  }
  memset(dp, INF, sizeof dp);
  dp[1] = 0;
  for(int i = 1; i <=n;i++){
    seeCheaper(i);
  }
  cout<<dp[n]<<endl;
}
