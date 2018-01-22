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

//int e[2005],c[2005],v[2005],ca[2005],cb[2005],cm[2005],va[2005],vb[2005],vm[2005];
vector<PII> expeditions; // cost, val
int n,c;

int dp[10000005];
int totExp = 0;
//get input
void knapsack(){
  //memset(dp,-1,sizeof dp);
  for (int i = 1; i <= totExp; i++){
    for (int j = c; j >= expeditions[i].F; j--){
      dp[j] = max(dp[j],dp[j-expeditions[i].F] + expeditions[i].S);
    }
  }
  cout<<dp[c]<<endl;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>c;
  expeditions.PB({0, 0});
  for(int i = 0; i <n;i++){
    //cin>>e[i]>>c[i]>>v[i]>>ca[i]>>cb[i]>>cm[i]>>va[i]>>vb[i]>>vm[i];
    int e,c,v,ca,cb,cm,va,vb,vm;
    cin>>e>>c>>v>>ca>>cb>>cm>>va>>vb>>vm;
    totExp+= e;
    int lastCost = -1;
    int lastVal = -1;
    for(int i = 0; i <e;i++){
      if(lastCost != -1){
        int curCost = (lastCost*ca + cb)%cm;
        int curVal = (lastVal*va + vb)%vm;
        expeditions.PB({curCost, curVal});
        lastCost = curCost;
        lastVal = curVal;
      }else{
        expeditions.PB({c, v});
        lastCost = c;
        lastVal = v;
      }
    }
  }
  for(PII e: expeditions){
    cout<<e.F<<" "<<e.S<<endl;
  }
  knapsack();
}
