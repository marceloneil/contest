//adj list
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int N, M, A, B, C, vis[1001], dist[1001];
vector<pair<int, int>> graph[1001];

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
    graph[A].push_back(make_pair(B, C));
    graph[B].push_back(make_pair(A, C));
  }
  dijkstra_list(1);
  //note: if it is impossible to get from the node specified (in this case 1) to another, it's dist will be INF
}
