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

int dp[10003][1003]; // time left to save, nth student
int v[10003],s[10003],t[10003];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>v[i]>>s[i]>>t[i];
  }
  for(int i =1;i<=n;i++){
    for(int a = 1 ; a <=1000;a++){
      if(t[i] >= i){
        if(a-s[i] >=1){
          dp[i][a] = max(dp[i-1][a], dp[i-1][a-s[i]] + v[i]);
        }
      }else{
        dp[i][a] = dp[i-1][a];
      }
    }
  }
  /*
  for(int i = 1; i <=n;i++){
    for(int a = 1; a <=90;a++){
      cout<<dp[i][a]<<" ";
    }
    cout<<endl;
  }*/


  cout<<dp[n][1000]<<endl;
}
