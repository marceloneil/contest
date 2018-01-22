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
#define ll long long
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

//I definitely need a 2d prefix sum array because I am finding the sun of rectangles
int n,m,arr[52][52],prefixSum[52][52];
int dp[54][54][54][54];

int findVal(int x1,int y1, int x2, int y2){
  return prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
}

int calc(int x1,int y1, int x2, int y2){
  if(dp[x1][y1][x2][y2] != INF) return dp[x1][y1][x2][y2];
  if((x1 == x2)&&(y1==y2)) return dp[x1][y1][x2][y2] = 0;// arr[x1][y1];
  for(int i = x1; i < x2;i++){
    dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], calc(x1,y1,i,y2) + calc(i+1,y2,x2,y2) + findVal(x1,y1,x2,y2));
  }
  for(int i = y1; i < y2;i++){
    dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], calc(x1,y1,x2,i) + calc(x2,i+1,x2,y2) + findVal(x1,y1,x2,y2));
  }
  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<dp[x1][y1][x2][y2]<<endl;
  //cout<<dp[x1][y1][x2][y2]<<endl;
  return dp[x1][y1][x2][y2];
}
//x = n
//y = m
int main(){
  memset(dp, INF, sizeof dp);
  scanf("%d %d",&n,&m);
  for(int i = 1 ; i <= n;i++){
    for(int a = 1; a <= m;a++){
      scanf("%d", &arr[i][a]);
      prefixSum[i][a] = prefixSum[i-1][a] + prefixSum[i][a-1] - prefixSum[i-1][a-1] + arr[i][a];
    }
  }
  //cout<<findVal(2,2,1,2);
  cout<<calc(1,1,n,m)<<endl;


}
