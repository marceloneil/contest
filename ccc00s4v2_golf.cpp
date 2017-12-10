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

int dp[5285],clubs[34];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int d,c;
  cin>>d>>c;
  for(int i = 1; i <=c;i++){
    cin>>clubs[i];
  }
  memset(dp, INF, sizeof dp);
  dp[1] = 0;
  for(int i = 1; i <=d;i++){
    for(int a = 1; a <=c;a++){
      dp[i + clubs[a]] = min(dp[i + clubs[a]], dp[i] + 1);
    }
  }
  if(dp[d+1] == INF){
    cout<<"Roberta acknowledges defeat."<<endl;
    return 0;
  }
  cout<<"Roberta wins in " + to_string(dp[d+1]) + " strokes."<<endl;
}
