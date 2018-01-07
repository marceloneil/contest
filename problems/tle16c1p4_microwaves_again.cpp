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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int n,m,k;
int edges[101][101];
VPII curEdges[101];
int val[101],maxAns;

int dist[101][101];
void floydwarshall(){
  for (int k = 1; k <=n;k++){
    for (int i = 1; i <=n;i++){
      for (int j = 1; j <=n;j++){
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i =1;i<=n;i++){
    cin>>val[i];
  }
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a][b] = c;
    edges[b][a] = c;
  }
  for(int i = 1; i<=n;i++){
    for(int a = 1; a<=n;i++){
      curEdges[a] = edges[a];
    }
    maxAns = -1;
    dijkstra(i);
  }
}
