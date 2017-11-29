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

VPII edges[200005];
ll maxDist = -1;

ll dist[100005],dist2[100005];
bool vis[100005];
priority_queue<pair<int,int> > q;

void dijkstra(int root){
  memset(dist, INF, sizeof dist);
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (pair<int,int> u: edges[cur]){
      if (!vis[u.F]){
        ll newDist = dist[cur] + u.S;
        if (newDist < dist[u.F]){
          dist[u.F] = newDist;
          maxDist = max(maxDist,newDist);
          q.push(make_pair(newDist,u.F));
        }
      }
    }
  }
}

ll theMaxDist = -1;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i = 0; i <m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }
  dijkstra(0);
  theMaxDist = maxDist;
  for(int i = 0 ; i <n;i++){
    dist2[i] = dist[i];
  }
  for(int i = 1; i <n;i++){
    memset(vis, 0, sizeof vis);
    maxDist = -1;
    dijkstra(i);
    theMaxDist = max(theMaxDist, dist[n-1] + dist2[i]);
  }
  cout<<theMaxDist<<endl;
}
