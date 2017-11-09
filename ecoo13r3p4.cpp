#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int main(){
  int n;
  int arr[1006][2];
  int dp[1006];
  scanf("%d",&n);
  for(int i = 0 ; i < n;i++){
    scanf("%d",&arr[i][0]);
    scanf("%d",&arr[i][1]);
  }
  for(int i = 0 ; i < n;i++){
    dp[i] = max(dp[i-1] + max(), ;
    if(dp[])
  }
  cout<<dp[1]<<endl;
}
