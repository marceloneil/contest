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

int c,n;
int weight[1003], val[1003];
int dp[1003];

//get input
void knapsack(){
  for (int i = 1; i <= n; i++){
    for (int j = c; j >= weight[i]; j--){
      dp[j] = max(dp[j],dp[j-weight[i]] + val[i]);
    }
  }
  cout<<dp[c]<<endl;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>c;
  for(int i = 1;i<=n;i++){
    cin>>val[i]>>weight[i];
  }
  knapsack();
}
