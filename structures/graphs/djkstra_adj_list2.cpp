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
typedef vector<VI> VVI;
typedef vector<PII> VPII;
typedef map<int,int> MII;

VPII edges[1005]; // nextnode, weight of edge

int n,m;
int dist[1005];
bool vis[1005];

struct CompareByFirst { // PQ goes from smallest to greatest [2,4,7...22,28,31] .... I THINK NOT SURE
  constexpr bool operator()(PII &a, PII &b)
  const noexcept{
    return a.F > b.F;
  }
};
priority_queue<PII, vector<PII>, CompareByFirst> q;

void dijkstra(int root){
  memset(dist, INF, sizeof dist);
  dist[root] = 0;
  q.push({0,root});
  while(!q.empty()){
    PII cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (PII u : edges[cur]){
      if(!vis[u.F]){
        int newDist = dist[cur] + u.S;
        if (newDist < dist[u.F]){
          dist[u.F] = newDist;
          q.push({newDist,u.F});
        }
      }
    }
  }
}
