#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
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

vector<PII> edges[20]; // nextnode, weight of edge

int n,m;
int dist[20], low[20];
bool vis[20];

void dfs(int start, int dist, int parNode){
  if(start == n-1) return;
  for(PII n : edges[start]){
    if(low[n.F] > low[parNode]){ // make sure it doesn't cut itself off
      if(dist)
      dfs(n,dist + n.S, parNode);
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }
  memset(low,INF,sizeof low);


  cout<<dist[n-1]<<endl;
}
