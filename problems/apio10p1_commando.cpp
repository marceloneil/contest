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

int n,a,b,c;
ll soldiers[1000005];
ll dp[1000005];
ll dp2[1000005];
ll psa[1000005];

/*
ll calc(int l, int r){ // [..]
int x = psa[r] - psa[l-1];
if(dp2[x] != INF){
return dp2[x];
}else{
return dp2[x] = ((a*x*x) + (b*x) + (c));
}
}*/
ll calc(int l, int r){ // [..]
  int x = psa[r] - psa[l-1];
  return (a*x*x) + (b*x) + (c);
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(dp2, INF,sizeof dp2);
  cin>>n;
  cin>>a>>b>>c;
  for(int i = 1; i <=n;i++){
    cin>>soldiers[i];
    psa[i] = psa[i-1] + soldiers[i];
  }
  for(int i = 1;i <= n;i++){
    //dp[i] = max(0,calc(1,i));
    for(int a = 0; a<i;a++){
      //cout<<a<<" "<<calc(1,a)<<endl;
      dp[i] = max(dp[i],dp[a] + calc(a+1,i));
    }
  }
  for(int i = 1;i<=n;i++){
    //cout<<dp[i]<<endl;
  }
  cout<<dp[n]<<endl;
}
