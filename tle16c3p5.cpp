//nope nope nope nope nope. I am going about this in the wrong way

#include <bits/stdc++.h>
using namespace std;

#define MAXN 355
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
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

int r,c,m,dp[MAXN][MAXN], maxSide;
vector< pair<int,int> > coords;

int findLargestSquare(){
  maxSide = 0;
  //memset(grid, 0, sizeof(grid));
  for(int i = 0 ; i < MAXN;i++){
    for(int a = 0; a < MAXN; a++){
      dp[i][a] = 0;
    }
  }
  for(int i = 0; US i < coords.size();i++){
    dp[coords[i].F][coords[i].S] = INF;
  }
  for(int i = 1; i <= r; i++){
    for(int a = 1; a <= c; a++){
      if(dp[i][a] != INF){ // if the curr cell is empty then give it a score
        dp[i][a] = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1])) + 1;
        maxSide = max(maxSide,dp[i][a]);
      }
    }
  }
  return maxSide;
}

int main(){
  scanf("%d %d %d",&r,&c,&m);
  for(int i = 0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    coords.push_back(make_pair(u,v));
    printf("%d\n", findLargestSquare());
  }
}
