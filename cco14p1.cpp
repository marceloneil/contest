#include <bits/stdc++.h>
using namespace std;

#define MAXN 205
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


int dp[MAXN][MAXN][MAXN/2];
int arr[MAXN][MAXN];

int calc(int x, int y, int s){
  if(dp[x][y][s] != -1){
    return dp[x][y][s];
  }
  if(s == 1){
    dp[x][y][1] = arr[x][y];
    return dp[x][y][1];
  }
  if(calc(x,y,s-1) && calc(x,y-1,s-1) && calc(x-1,y,s-1) && calc(x+1,y,s-1)){
    dp[x][y][s] = 1;
    return 1;
  }
  return 0;
}


int main(){
  int n,count;
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for(int i = 1; i <=n;i++){
    for(int a = 1; a<=n;a++){
      char temp;
      scanf("%c", &temp);
      cout<<temp<<endl;
      if(temp == '#'){
        dp[i][a][1] = 1;
      }
    }
  }

  for(int i = 1;i<=n;i++){
    for(int a = 1; a<=n;a++){
      for(int s = 1; s<=n;s++){
        count+=calc(i,a,s);
      }
    }
  }
  printf("%d", count);
}
