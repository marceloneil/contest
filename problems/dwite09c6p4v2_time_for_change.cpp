//lol I didn't event try and test this solution

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
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

// m is size of coins array (number of different coins)
int dp[103],coins[103],sums[103];
void minCoins(int m, int V){
  memset(dp,INF,sizeof dp);
  dp[0] = 0;
  for (int i=1; i<=V; i++){
    for (int j=0; j<m; j++){
      if (coins[j] <= i){
        int sub_res = dp[i-coins[j]];
        if (sub_res != INF && sub_res + 1 < dp[i]){
          dp[i] = sub_res + 1;
          sums[i] = sums[i-coins[j]] + coins[j];
        }
      }
    }
  }
}

int main(){
  for(int i = 1; i <=5;i++){
    int n,w;
    scanf("%d %d",&n,&w);
    for(int i =0;i<w;i++){
      scanf("%d",&coins[i]);
    }
    minCoins(w,n);
    //cout<<dp[n]<<" "<<sums[n];
    cout<<dp[n]<<endl;
  }
}
