#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

int N, M, dist[MAXN], vis[MAXN];
vector<pii> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int root){
  memset(dist,INF, MAXN);
  memset(vis,false, MAXN);
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!pq.empty()){
    pair cur_pair = pq.top(); pq.pop();
    int cur_dist = cur_pair.first; int cur = cur_pair.second;
    if (vis[cur]) continue;
    vis[cur] = true;
    for (pii i : adjList[cur]){
      if (vis[cur]){
        int newDist = dist[cur] + cost[cur][u];
        if (newDist < dist[u]){
          dist[u] = newDist;
          pq.push(make_pair(newDist,u));
        }
      }
    }
  }
}

int main(){
  cin >> N >> M;

  for (int i = 0, a, b, w; i < M; i++){
    cin >> a >> b >> w;
    adjList[a].push_back({b, w});
    adjList[b].push_back({a, w});
  }
  dijkstra(1);
  for(int i = 0 ; i < MAXN; i++){
    if(dist[i] != INF){
      cout<< dist[i]<<endl;
    }
  }
}
