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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

int dp[1005][3005];
struct item{
  int v,c;
  item(int cc, int vv){
    v = vv;
    c = cc;
  };
  item();
};
vector<item> bag[7];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int tt,n,b;
  cin>>tt>>n;
  for(int i =1; i<=n;i++){
    int x,y,z;
    cin>>x>>y>>z;
    bag[z].PB(item(x,y));
  }
  //memset(dp,INF,sizeof dp);
  cin>>b;
  dp[1][1] = 0;
  dp[0][0] = 0;
  for(int i = 0; i <1005;i++){
    //dp[i][0] = -1;
  }
  for(int i = 1; i <=tt;i++){ // item type
    while(!bag[i].empty()){
      item it = bag[i].back();bag[i].pop_back();
      for(int a = 1; a<=b;a++){ // cost
        if(a-it.c >= 0){
          //dp[i][a] = max(dp[i][a],max(dp[i-1][a-it.c] + it.v, dp[i][a-1]));
          //if(dp[i-1][a-it.c] > 0 && (i-1 != 0)){
            dp[i][a] = max(dp[i][a],dp[i-1][a-it.c] + it.v);
          //}
        }
      }
    }
  }
  for(int i = 1; i <=2;i++){
    for(int a = 1; a <=b;a++){
      //cout<<dp[i][a]<<" ";
    }
    //cout<<endl;
  }
  if(dp[tt][b] == 0){
    cout<<-1;
    return 0;
  }
  cout<<dp[tt][b]<<endl;
}
