// this WAs and TLEs. so I need a faster solution than n^2 rip

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

vector<int> edges[1505]; // nextnode, weight of edge
bool vis[1505];
int n,m,k;

int bfs(int cur){
  memset(vis, 0, sizeof vis);
  int ans = 0;
  queue<PII> q;
  q.push({cur,k});
  vis[cur] = 1;
  while(!q.empty()){
    PII cur = q.front(); q.pop();
    if(cur.S == 0){
      ans++;
    }
    for(int u : edges[cur.F]){
      if(!vis[u]){
        vis[cur.F] = 1;
        q.push({u,cur.S-1});
      }
    }
  }
  return ans;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i = 1; i <=m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
    edges[b].PB(a);
  }
  for(int i =1;i<=n;i++){
    cout<<bfs(i)+1<<endl;
  }
}
