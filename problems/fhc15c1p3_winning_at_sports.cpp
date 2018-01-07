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

int y,o;
ll dp[2003][2003];
ll dp2[2003][2003];

ll sfw(int a, int b){ // stressFreeWins
  if(dp[a][b] != -1){
    return dp[a][b];
  }
  if(a == y && b == o){
    return dp[a][b] = 1;
  }
  if(a > o && b == o){
    return dp[a][b] = 1;
  }else if(b == o){
    return dp[a][b] = 0;
  }
  if(a == y){
    return dp[a][b] = 1;
  }
  if(a >0 && a <= b){
    return dp[a][b] = 0;
  }
  return dp[a][b] = sfw(a+1, b)%MOD + sfw(a,b+1)%MOD;
}

ll sflw(int a, int b){ // stressFullWins
  if(dp2[a][b] != -1){
    return dp2[a][b];
  }
  if(a == y && b == o){
    return dp2[a][b] = 1;
  }
  if(a > b){
    return dp2[a][b] = 0;
  }
  if(b == o){
    return dp2[a][b] = 1;
  }
  return dp2[a][b] = sflw(a+1, b)%MOD + sflw(a,b+1)%MOD;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 1; i <=t;i++){
    scanf("%d-%d",&y,&o);
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp);
    cout<<"Case #" +to_string(i)+ ": "<<sfw(0,0)<<" "<<sflw(0,0)<<endl;
  }
}
