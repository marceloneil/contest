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

int n,m,t;


int dist[1005],vis[1005];
vector<int> edges[1005];
priority_queue<pair<int,int> > q;

void dijkstra(int root){
  for(int i = 0; i <1005;i++){
    dist[i] = INF;
  }
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (int u: edges[cur]){
      if (!vis[u]){
        int newDist = dist[cur] + t;
        if (newDist < dist[u]){
          dist[u] = newDist;
          q.push(make_pair(newDist,u));
        }
      }
    }
  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>t;
  for(int i = 1 ; i <=m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
    //edges[b].PB(a);
  }
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    memset(vis, 0 , sizeof vis);
    dijkstra(a);
    if(dist[b] == INF){
      cout<<"Not enough hallways!"<<endl;
      continue;
    }
    cout<<dist[b]<<endl;
  }
  /*
  for(int i = 1; i <=n;i++){
    cout<<dist[i]<<endl;
  }*/
}
