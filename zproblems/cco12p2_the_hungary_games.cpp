#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
//#define aall(x) x, x + n // #define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 100005


int n,m;
int dist[20005];
int dist2[20005];
bool vis[20005];
bool vis2[20005];
VPII edges[20005];

struct CompareByFirst {
  constexpr bool operator()(PII a, PII b)
  const noexcept{
    return a.first > b.first;
  }
};
priority_queue<PII, vector<PII>, CompareByFirst> q;

void dijkstra(int root){
  memset(dist, INF, sizeof dist);
  memset(dist2, INF, sizeof dist2);
  dist[root] = 0;
  q.push({0,root});
  while(!q.empty()){
    PII cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur] && vis2[cur]) continue;
    if(vis[cur]){
      vis2[cur] = 1;
    }else{
      vis[cur] = 1;
    }
    for (PII u : edges[cur]){
      if(!(vis2[u.F] && vis[u.F])){
        int newDist = dist[cur] + u.S;
        int newDist2 = dist2[cur] + u.S;
        if (newDist < dist[u.F]){
          dist2[u.F] = min(dist[u.F], newDist2);
          dist[u.F] = newDist;
          q.push({newDist,u.F});
        }else if(newDist < dist2[u.F] && newDist != dist[u.F]){
          dist2[u.F] = newDist;
          q.push({newDist,u.F});
        }
      }
    }
  }
}


int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n,m;
  cin>>n>>m;
  for(int i = 1; i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
  }
  dijkstra(1);
  cout<<dist2[n]<<endl;
}
