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

vector<int> edges[30003];

int dist[30003];
bool vis[30003];
struct CompareByFirst {
  constexpr bool operator()(pair<int, int> const & a, pair<int, int> const & b)
  const noexcept{
    return a.first > b.first;
  }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, CompareByFirst> q;

int n,m;
void dijkstra(int root){
  memset(dist,INF,sizeof dist);
  dist[root] = 0;
  q.push({0,root});
  while (!q.empty()){
    PII cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (int u: edges[cur]){
      if (!vis[u]){
        int newDist = dist[cur] + 1;
        if (newDist < dist[u]){
          dist[u] = newDist;
          q.push({newDist,u});
        }
      }
    }
  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin>>n>>m;
  for(int i = 0; i <m;i++){
    int a,b;
    cin>>a>>b;
    if(a-b >= 0){
      edges[a].PB(a - b);
      edges[a - b].PB(a);
    }
    if(a+b <n ){
      edges[a].PB(a + b);
      edges[a + b].PB(a);
    }
  }
  dijkstra(0);
  if(dist[1] == INF){
    printf("%d", -1);
  }else{
    printf("%d",dist[1]);
  }
}
