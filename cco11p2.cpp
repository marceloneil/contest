//This question is pretty ez. All I have to do is run two djiekstras. One for the minimum distance to the last node (from the tunnels)
// and one for the minimum amount of sunshine to each node
//if the minimum amount of sunshine to the last node exceeds s, then output -1. (I should calculate this djiekstra first)

#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;
int s,n,e;

int max;
/*
int goToOthers(int currentPoint, vector<int> visitedPoints, int sunLeft){
if (sunLeft < 0){
return -1;
}
return 0;
}*/

map<int, vector<int>> edges;





int dist[MAXN], pred[MAXN];
vector<pair<int, int> > adj[MAXN];
void dijkstra(int nodes, int start) {

  vector<bool> vis(nodes, false);
  for (int i = 0; i < nodes; i++) {
    dist[i] = INF;
    pred[i] = -1;
  }
  int u, v;
  dist[start] = 0;
  priority_queue<pair<int, int> > pq;
  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    u = pq.top().second;
    pq.pop();
    vis[u] = true;
    for (int j = 0; j < (int)adj[u].size(); j++) {
      if (vis[v = adj[u][j].first]) continue;
      if (dist[v] > dist[u] + adj[u][j].second) {
        dist[v] = dist[u] + adj[u][j].second;
        pred[v] = u;
        pq.push(make_pair(-dist[v], v));
      }
    }
  }
}
//Use the precomputed pred[] array to print the path
void print_path(int dest) {
  int i = 0, j = dest, path[MAXN];
  while (pred[j] != -1) j = path[++i] = pred[j];
  cout << "Take the path: ";
  while (i > 0) cout << path[i--] << "->";
  cout << dest << ".\n";
}
int main() {
  int nodes, edges, u, v, w, start, dest;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
  }
  cin >> start >> dest;
  dijkstra(nodes, start);
  cout << "The shortest distance from " << start;
  cout << " to " << dest << " is " << dist[dest] << ".\n";
  print_path(dest);
  return 0;
}








int main(){
  scanf("%d %d %d",&s,&n,&e);
  for (int i = 0;i<e;i++){
    int u,v;
    scanf("%d %d", &u,&v);
    //the tunnels are bi-drectional
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}
