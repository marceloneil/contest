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

int dist[100005],vis[100005];
priority_queue<pair<int,int> > q;
int n,m,x,y;
vector<pair<int,int>> edges[100005];

void dijkstra(int root){
  memset(dist,INF,sizeof dist);
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (pair<int,int> u: edges[cur]){
      if (!vis[u.F]){
        int newDist = dist[cur] + u.S;
        if (newDist < dist[u.F]){
          dist[u.F] = newDist;
          q.push(make_pair(newDist,u.F));
        }
      }
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>x>>y;
  REP(i,1,m){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }
  dijkstra(x);
  dijkstra(y);
  int q1;
  cin>>q1;
  while(q1--){
    
  }
}
