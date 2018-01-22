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

int l,d,x,y;

int vals[1003][1003];
int dp[1003][1003];

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>l>>d;
  for(int i = 1; i <=d;i++){
    for(int a = 1; a <=l;a++){
      cin>>vals[i][a];
    }
  }
  cin>>x>>y;
  memset(dp,INF,sizeof dp);
  dp[1][0] = 0;
  dp[0][1] = 0;

  for(int i = 1; i <=d;i++){
    for(int a = 1; a <=l;a++){
      dp[i][a] = vals[i][a] +  min(dp[i-1][a], dp[i][a-1]);
    }
  }
  for(int i = 2; i <=d;i++){
    for(int a = l; a >=1;a--){
      dp[i][a] = min(dp[i][a],vals[i][a] + min(dp[i-1][a], dp[i][a+1]));
    }
  }
  cout<<dp[x+ 1][y+1]<<endl;
}
