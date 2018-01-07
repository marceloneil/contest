#include <bits/stdc++.h>
using namespace std;

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
typedef vector<PII> VPII;
#define MN 100005


int dist[1004],relaxCnt[1004];
bool pushed[1004];
VPII edges[1004];
int n,m;

void spfa(int root){
  memset(dist, INF, sizeof dist);
  dist[root] = 0;
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int nd = q.front(); q.pop();
    pushed[nd] = 0;
    for(pair<int,int> u: edges[nd]){
      if(dist[nd] + u.S < dist[u.F]){
        relaxCnt[u.F]++;
        if(relaxCnt[u.F]>=n){
          // negative cycle found bc the node is relaxed more than n-1 times
        }
        dist[u.F] = dist[nd] + u.S;
        if (!pushed[u.F]){ //use bool array
          pushed[u.F] = 1;
          q.push(u.F);
        }
      }
    }
  }
}


int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  // finding the shortest path from 1 to n
  cin>>n>>m;
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
  }
  spfa(1);
  cout<<dist[n]<<endl;
}
