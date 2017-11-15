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
#define ll long long
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

//get minimum value from the maximum spanning tree
int edges[10005][10005];

int dist[10005],vis[10005],minPreference[10005];
priority_queue<pair<int,int> > q;

void dijkstra(int root){
  memset(dist,-1,sizeof dist);
  memset(minPreference,-1,sizeof minPreference);
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for(int i = 1; i <5005;i++){
      if (edges[cur][i] != -1 && !vis[i]){
        int newDist = dist[cur] + edges[cur][i];
        if (newDist > dist[i]){
          dist[i] = newDist;
          q.push(make_pair(newDist,i));
        }
      }
    }
  }
}


int main(){
  memset(edges,-1,sizeof edges);
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a][b] = c;
    edges[b][a] = c;
  }
}
