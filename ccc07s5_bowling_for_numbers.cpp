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

int arr[30003];
int dp[503][30003];
int n,k,w;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cin>>n>>k>>w;
    for(int i =1;i<=n;i++){
      cin>>arr[i];
      dp[0][i] = dp[0][i-1] + arr[i];
      if(i > w){
        dp[0][i] -= arr[i-w];
      }
    }
    for(int i = 1; i <=k;i++){
      for(int a = 1; a <=w;a++)dp[i][a] = dp[i-1][a];
      for(int a = w + 1; a <=n;a++){
        if(i == 1){
          dp[i][a] = max(dp[i][a-1],dp[0][a]);
        }else{
          dp[i][a] = max(dp[i-1][a-w] + dp[0][a], dp[i][a-1]);
        }
      }
    }
    cout<<dp[k][n]<<endl;
  }
}
