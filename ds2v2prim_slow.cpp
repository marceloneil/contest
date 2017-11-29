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
#define ll long long
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

bool vis[100005]; int dist[100005]; int parent[100005];
vector<pair<int,int> > edges[100005];
int n,m;
void prim(int root){
  memset(dist,9999999, sizeof dist);
  dist[root] = 0;
for(int i = 1 ; i <=n;i++){
  if(!vis[i]){
    vis[i] = 1;
    for(pair<int,int> nd : edges[i]){
      if (!vis[nd.F]){
        if (cost[cur][u] < dist[u]){
          dist[u] = cost[cur][u];

          parent[u] = cur;

        }
      }
    }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].push_back({b,i});
    edges[b].push_back({a,i});
  }
  prim(1);
  if(diffNodesVisited != n){
    cout<<"Disconnected Graph"<<endl;
    return 0;
  }
  while(!holdAns.empty()){
    cout<<holdAns.top()<<endl;
    holdAns.pop();
  }
}
