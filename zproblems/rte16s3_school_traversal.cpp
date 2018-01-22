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


vector<PII> edges[6005];


int diste[6005],height[6005],parBlock[6005];
void dfs(int cur, int par, int dist){
  diste[cur] = dist;
  for(PII u : edges[cur]){
    if(u.F != par){
      dfs(u.F,cur,dist + u.S);
    }
  }
}

int lca(int a, int b){

  if(height[a] == height[b]){

  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,qu;
  cin>>n;
  for(int i = 1; i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }
  dfs(0,-1,0);
  cin>>qu;
  while(qu--){
    int x,y;
    cin>>x>>y;
    cout<<diste[x] + diste[y] - 2*diste[lca(x,y)]<<endl;;

  }
}
