//WTF MY PRIORITY QUEUE IS BROKEN. IT DOESN'T RETURN THE SMALLEST

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

vector<PII> edges[1005]; // nextnode, weight of edge

int n,m;
int dist[1005];
bool vis[1005];

struct CompareByFirst {
  constexpr bool operator()(pair<int, int> const & a, pair<int, int> const & b)
  const noexcept{
    return a.first > b.first;
  }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, CompareByFirst> q;

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


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n>>m;
  for (int i = 1; i <= m; i++){
    int a, b, w;
    cin>>a>>b>>w;
    edges[a].PB({b, w});
    edges[b].PB({a, w});
  }

  dijkstra(1);
  for(int i = 1 ; i <= n; i++){
    if(dist[i] != INF){
      cout<< dist[i]<<endl;
    }else{
      cout<<-1<<endl;
    }
  }
}
