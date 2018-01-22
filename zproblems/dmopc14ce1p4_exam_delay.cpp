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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

int n,m;
struct edge{
  int end,d,s;
  double t;
  edge(int b,int dd, int ss){
    end = b;
    d = dd;
    s = ss;
    t = d/s;
  };
};
vector<edge> edges[1005]; // nextnode, weight of edge

int dist[1005];
bool vis[1005];

struct CompareByFirst {
  constexpr bool operator()(pair<double, int> const & a, pair<double, int> const & b)
  const noexcept{
    return a.first > b.first;
  }
};
priority_queue<pair<double, int>, vector<pair<double, int> >, CompareByFirst> q;

void dijkstra(int root){
  for(int i = 0; US i < sizeof dist;i++){
    dist[i] = 1000.0;
    cout<<"ji"<<endl;
  }
  dist[root] = 0;
  q.push({0,root});
  while(!q.empty()){
    PII cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (edge u : edges[cur]){
      if(!vis[u.end]){
        double newDist = dist[cur] + u.t;
        cout<<newDist<<endl;
        if (newDist < dist[u.end]){
          dist[u.end] = newDist;
          q.push({newDist,u.end});
        }
      }
    }
  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1;i<=m;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    edges[b].PB(edge(a,c,d));
    edges[a].PB(edge(b,c,d));
  }
  dijkstra(1);
  cout<<dist[7]<<endl;
  cout<<dist[n]<<endl;

}
