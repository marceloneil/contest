#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
/*int main(){
int n,m;
cin>>n>>m;
//vector<vector<int> > arr(n);
bool nodes[n];
set<vector<int> > arr;
for(int i = 0; i < n; i ++){
int u,v;
cin>>u>>v;
if(nodes[v] == false){
vector<int> temp;
temp.push_back(u);
temp.push_back(v);
arr.insert(temp);
nodes[v] = true;
}
}
for (vector<int> node : arr){
cout<<node[0] + " "<<endl;
}
}
*/
struct node{
  int value;
  vector<node> neighbors;
  node(int val){
    value = val;
  }
  void add_neighbor(node n){
    neighbors.push_back(n);
  }
};

int dist[1000005], parent[1000005]; bool vis[1000005], int edges[1000005][1000005];
priority_queue<pair<int,node> > q;
void prim(node root){
  //init vis and dist here
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,node> cur_pair = q.top(); q.pop();
    int cur_dist = cur_pair.first; node cur = cur_pair.second;
    if (!vis[cur.value]) continue;
    vis[cur.value] = 1;
    //do what you want with edge (use parent[])
    for (node u : cur.neighbors){
      if (!vis[u.value]){
        if (edges[cur.value][u.value] < dist[u.value]){
          dist[u] = edges[cur][u];
          parent[u] = cur;
          q.push(make_pair(dist[u],u));
        }
      }
    }
  }
}

/*
const int maxn = 100005;
//why does node* parent[maxn]; work but node parent[maxn]; doesn't?
bool vis[maxn]; int dist[maxn]; node* parent[maxn];
void prim(node root){
memset(dist,0x3f3f3f3f,sizeof(dist));
dist[root] = 0;
while (there are nodes left){
node cur = unvisited node with lowest distance;
mark cur as visited;
//do what you want with edge (use parent[])
for (every node u adjacent to cur){
if (u is not visited){
if (cost[cur][u] < dist[u]){
dist[u] = cost[cur][u];
parent[u] = cur;
}
}
}
}
}*/



int main(){
  int n,m;
  cin>>n>>m;
  for(int i = 0; i < m; i ++){

  }
}
