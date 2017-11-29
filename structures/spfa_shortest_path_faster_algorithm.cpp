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

//Initialize all dists to infinity
int dist[1004];
bool pushed[1004];
vector<pair<int,int>>edges[1004];

void spfa(int root){
  dist[root] = 0;
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int nd = q.front(); q.pop();
    pushed[nd] = 0;
    for(pair<int,int> u: edges[nd]){
      if(dist[nd] + u.S < dist[u.F]){
        dist[u.F] = dist[nd] + u.S;
        if (!pushed[u.F]){ //use bool array
          pushed[u.F] = 1;
          q.push(u.F);
        }
      }
    }
  }
}
