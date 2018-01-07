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


int n,m;
int vis[100005],dist[100005],parent[100005];
vector<pair<int,int> > edges[100005];

stack<int> holdAns;

priority_queue<pair<int,int> > q;
int diffNodesVisited = 0;
void prim(int root){
  //init vis and dist here
  dist[root] = 0;
  memset(dist,9999999,sizeof dist);
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    diffNodesVisited++;

    for(pair<int,int> nd : edges[cur]){
      int nxtnd = nd.F;
      int edgeCost = nd.S;
      if(!vis[nxtnd]){
        if (edgeCost < dist[nxtnd]){
          dist[nxtnd] = edgeCost;
          parent[nxtnd] = cur; // the mst edge of this node is the corresponding val in this idx of parent
          holdAns.push(edgeCost);
          q.push(make_pair(dist[nxtnd],nxtnd));
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
  /*
  for(int i = 1;i<=n;i++){
    for(pair<int,int> anedge: edges[parent[i]]){
      if(anedge.F == i){
        cout<<anedge.S<<endl;
      }
    }
  }*/
}
