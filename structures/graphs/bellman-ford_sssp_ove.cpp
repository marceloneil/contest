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
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int dist[5005];
VPII edges[5005]; // in pair: nextnode,cost
int n,m;

void bellmanFord(int source){
  memset(dist, INF, sizeof dist);
  dist[source] = 0;

  for(int a = 1; a <=n-1;a++){ // relax all edges n-1 times
    for(int i = 1; i <=n;i++){
      for(PII e : edges[i]){
        if (dist[i] + e.S < dist[e.F]){
          dist[e.F] = dist[i] + e.S;
          //can use a parent array to find paths
        }
      }
    }
  }

  //check for negative cycles
  for(int i = 1; i <=n;i++){
    for(PII e : edges[i]){
      if (dist[i] + e.S < dist[e.F]){
        //negative cycle found
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
  bellmanFord(1);
  cout<<dist[n]<<endl;
}
