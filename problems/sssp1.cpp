#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

int N, M, dist[MAXN], vis[MAXN];
vector<pii> adjList[MAXN];
bool checkRemaining(){
  for(int i = 0 ; i < MAXN; i++){
    if(vis[i] == false){
      return true;
    }
  }
  return false;
}

int indexofSmallestElement(){
  int curr = dist[0];
  int index = 0;
  for(int i = 1; i < MAXN; i++){
    if(dist[i] < curr && vis[i] == false){
      curr = dist[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int root){
  memset(dist,INF, MAXN);
  memset(vis,false, MAXN);
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (checkRemaining()){
    int curr = indexofSmallestElement();
    vis[curr] = true;
    for (pii i : adjList[cur]){
      if (vis[cur]){
        int newDist = dist[cur] + cost[cur][u];
        if (newDist < dist[u]){
          dist[u] = newDist;
          q.push(make_pair(newDist,u));
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
