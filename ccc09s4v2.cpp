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

ll n,k,d;
ll t;
ll dist[5005];
int vis[5005],cost[5005][5005],edges[5005][5005];
priority_queue<pair<int,int> > q;

void dijkstra(int root){
  for(int i = 0; i <5005;i++){
    dist[i] = INF;
  }
  dist[root] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<ll,ll> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (int i = 1; i < 5003; i++){
      if(edges[cur][i] == 1 && !vis[i]){
        ll newDist = dist[cur] + cost[cur][i];
        if (newDist < dist[i]){
          dist[i] = newDist;
          q.push(make_pair(newDist,i));
        }
      }
    }
  }
}


ll minCost = INF;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  for(int i = 1; i <=t;i++){
    int x,y,c;
    cin>>x>>y>>c;
    edges[x][y] = 1;
    edges[y][x] = 1;
    cost[x][y] = c;
    cost[y][x] = c;
  }
  cin>>k;
  queue<pair<int,int> > price; // price, city
  for(int i = 1;i<=k;i++){
    int a,b;
    cin>>a>>b;
    price.push(make_pair(a,b));
  }
  cin>>d;
  dijkstra(d);
  while(!price.empty()){
    pair<ll,ll> thePrice = price.front(); price.pop();
    minCost = min(thePrice.F + dist[thePrice.S], minCost);
  }
  cout<<minCost<<endl;
}
