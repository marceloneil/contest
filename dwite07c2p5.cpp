#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
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

vector<int> edges[105],vis[105];
int dfs(int a, int b, int c, int d){
  vis[a] = 1;
  if(a == b) return 1;
  for(int z : edges[a]){
    if()
  }
}
int isBridge(int a, int b){
  memset(vis,0,sizeof vis);
  return dfs(a,b,a,b);
}

int main(){
  int n,m,ans;
  scanf("%d %d",&n,&m);
  for(int i = 0; i <m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= n;i++){
    for(int c : edges[i]){
      if(i < c){ // we only need to check to see if "half" of the edges are bridges.
        if(isBridge(i,c)) ans++;
      }
    }
  }
  printf("%d", ans);

}
