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


//answer is the minimum of the maximum spanning tree between the destination cities and the starting city
int edges[10005][10005];


int dist[10005], parent[10005];
bool vis[10005];
int c,r,d;
priority_queue<pair<int,int> > q;
void prim(int root){
  memset(dist, -1,sizeof dist);
  //init vis and dist here
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for(int i = 1 ; i <=r;i++){
      if(edges[cur][i] != -1 && !vis[i]){
        if (edges[cur][i] > dist[i]){
          dist[i] = edges[cur][i];
          parent[i] = cur; // the mstedge of this node is the corresponding val in this idx of parent
          q.push(make_pair(dist[i],i));
        }
      }
    }
  }
}

int main(){
  memset(edges,-1,sizeof edges);
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>c>>r>>d;
  for(int i = 1; i <=r;i++){
    int x,y,w;
    cin>>x>>y>>w;
    edges[x][y] = w;
    edges[y][x] = w;
  }
  for(int i = 1; i <=r;i++){
    cout<<dist[parent[i]]<<endl;
  }
  stack<int> dest;
  for(int i = 1; i <=d;i++){
    int temp;
    cin>>temp;
    dest.push(temp);
  }
}
