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

int dp[12][103], sizes[12];

int main(){
  int n,w;
  scanf("%d %d",&n,&w);
  memset(dp,-1,sizeof dp);
  vector<int> hold;

  for(int i =1;i<=w;i++){
    int temp;
    scanf("%d",&temp);
    hold.push_back(temp);
  }
  cout<<"rip seg fault"<<endl;
  sort(hold.begin(),hold.end());
  for(int i = 0;US i < sizeof hold;i++){
    sizes[i+1] = hold[i];
    dp[i][sizes[i+1]] = 1;
  }
  cout<<"hi"<<endl;
  for(int i = 1; i <=w;i++){
    for(int a = 1; a <=n;a++){
      if(dp[i][a - sizes[i]] != -1 || dp[i-1][a] != -1){
        if(dp[i][a - sizes[i]] == -1 ){
          dp[i][a] = dp[i-1][a];
        }else if(dp[i-1][a] == -1){
          dp[i][a] = dp[i][a - sizes[i]] +1;
        }else{
          dp[i][a] = min(dp[i][a - sizes[i]] + 1, dp[i-1][a]);
        }
      }
      //dp[a][i] = min(dp[a-1][i-sizes[a]] + 1, dp[a-1][i]);
    }
  }
  for(int i = 60;i<70;i++){
    cout<<dp[w][i]<<endl;
  }
  printf("%d", dp[w][n]);
}
