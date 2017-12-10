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

int arr[22][22],dp[22][22];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  memset(dp,-1,sizeof dp);
  int n;
  cin>>n;
  for(int i= 1; i <=n;i++){
    for(int a = 1 ; a <=n;a++){
      cin>>arr[i][a];
    }
  }
  for(int i= 1; i <=n;i++){
    for(int a = 1 ; a <=n;a++){
      //dp[i][a] =
    }
  }


}
