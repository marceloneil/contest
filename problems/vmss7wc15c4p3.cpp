//adj list
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int N, M, A, B, C, vis[100003], dist[100003], first[100003],tmax;
vector<pair<int, int>> graph[100003];

void dijkstra_list(int startNode) {
  memset(dist, INF, sizeof dist);
  dist[startNode] = 0;

  for (int num = 1; num <= N; num++) {
    int minNode = -1;
    int minDist = INF;

    for (int i = 1; i <= N; i++) {
      if (!vis[i] && dist[i] < minDist) { // if I haven't visited the node and the dist to it is less
        minDist = dist[i];
        minNode = i;
      }
    }

    if (minNode == -1)
      return;

    vis[minNode] = 1;

    for (int i = 0; (unsigned)i < graph[minNode].size(); i++) {
      int dest = graph[minNode][i].first;
      if (vis[dest])
        continue;
      int weight = graph[minNode][i].second;
      if (dist[minNode] + weight < dist[dest])
        dist[dest] = dist[minNode] + weight; // update dist to curr node
    }
  }
}


int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A, &B, &C);
    graph[A+1].push_back(make_pair(B+1, C+1));
    graph[B+1].push_back(make_pair(A+1, C+1));
  }
  dijkstra_list(1);
  for(int i = 1; i <= N;i++){
    first[i] = dist[i];
  }

  //wait. this is really slow. I'm literally running a floyd-warshall
  for(int i = 2; i <= N;i++){
    memset(vis, 0, sizeof vis);
    dijkstra_list(i);
    printf("%d %d\n",dist[N],first[N]);
    if(dist[N] + first[N] > tmax){
      tmax = dist[N] + first[N];
    }
  }
  printf("%d",tmax);
}
