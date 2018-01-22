//funny how convex hull is literally the same as the sunlight caves
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f


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


int main(){
/*  int h,n,e;//n = number of nodes, e = num edges
  cin>>h>>n>>e;
  int arr[n][n][2];
  memset( &arr[0][0][0], INF, sizeof(arr) );
  while(e--){
    int a,b,c,d; // from node a to b with cost c
    cin>>a>>b>>c>>d;
    arr[a][b][0] = c;
    arr[a][b][1] = d;
  }
  for(int k = 0; k < n;k++){
    for(int i = 0; i < n;i++){
      for(int j =0;j<n;j++){
        if(arr[i][k][1] + arr[k][j][1] < h){
          arr[i][j][0] = min(arr[i][j][0],arr[i][k][0] + arr[k][j][0]);
          arr[i][j][1] = min(arr[i][j][1],arr[i][k][1] + arr[k][j][1]);
        }
      }
    }
  }
  int s,f;
  cin>>s>>f;
  if(arr[s-1][f-1][0] == INF){
    cout<<-1<<endl;
  }else{
    cout<<arr[s-1][f-1][0]<<endl;
  }
  for(int i = 0 ;i<n;i++){
    for(int j =0; j < n;j++){
      cout<<arr[i][j][0]<<" ";
    }
    cout<<endl;
  }*/
  int h,n,e;//n = number of nodes, e = num edges
  //cin>>h>>n>>e;




}
