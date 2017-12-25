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

int dp[1025][50],arr[50];
int fullMask;
int n;
int calc(int mask, int i){
  if(dp[mask][i] != -1) return dp[mask][i];
  if(i == n){
    LL p=__builtin_popcount(mask);
    if(p<=k) return 1;
        else return 0;
  }
  for(int a = i; a <n;a++){
    calc(mask | (1<<a),i+1);
  }
}



int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  fullMask = (1<<n)-1;
  for(int i = 0; i <n;i++){
    cin>>arr[i];
  }
  memset(dp,-1,sizeof dp);

}
