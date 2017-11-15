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
#define ll long long
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;


int dist[5005],vis[5005],cost[5005][5005],edges[5005][5005];
priority_queue<pair<int,int> > q;

void dijkstra(int root){
  for(int i = 0; i <5005;i++){
    dist[i] = 10005;
  }
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for(int i = 1; i <5005;i++){
      if (edges[cur][i] && !vis[i]){
        int newDist = dist[cur] + cost[cur][i];
        if (newDist < dist[i]){
          dist[i] = newDist;
          q.push(make_pair(newDist,i));
        }
      }
    }
  }
}
