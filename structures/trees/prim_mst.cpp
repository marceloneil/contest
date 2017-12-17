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
    //do what you want with edge (use parent[])
    for(int i = 1 ; i <=r;i++){
      if(edges[cur][i] != -1 && !vis[i]){
        if (edges[cur][i] < dist[i]){
          dist[i] = edges[cur][i];
          parent[i] = cur;
          q.push(make_pair(dist[i],i));
        }
      }
    }
  }
}
