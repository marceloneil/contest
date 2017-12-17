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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int dist[5005];
vector<pair<int,int> > edges[5005]; // in pair: nextnode,cost
int n;

int bellmanFord(int source){
  memset(dist, INF, sizeof dist);
  dist[source] = 0;
  //compute the shortest paths
  for(int i = 1; i <=n-1;i++){
    for(pair<int,int> e : edges[i]){
      if (dist[i] + e.S < dist[e.F]){
        dist[e.F] = dist[i] + e.S;
        //can use a parent array to find paths
      }
    }
  }

  //check for negative cycles
  for(int i = 1; i <=n;i++){
    for(pair<int,int> e : edges[i]){
      if (dist[i] + e.S < dist[e.F]){
        //negative cycle found
      }
    }
  }
}
