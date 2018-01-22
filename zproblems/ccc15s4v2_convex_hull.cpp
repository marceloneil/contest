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


int dist[2001][201];
bool pushed[2001];
int k,n,m;

struct edg{
  int b,t,h;
  edg(int b2, int t2, int h2){
    b = b2;
    t = t2;
    h = h2;
  }
};

vector<edg> edges[2001];
priority_queue<pair<int,int> > q;

void dijkstra(int root){
  memset(dist,INF,sizeof dist);
  dist[root][0] = 0;
  q.push(make_pair(0,root));
  while (!q.empty()){
    pair<int,int> cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    pushed[cur] = 0;
    for (edg u: edges[cur]){
      for(int i = 0; i + u.h <k;i++){
        int newDist = dist[cur][i] + u.t;
        if (newDist < dist[u.b][i + u.h]){
          dist[u.b][i + u.h] = newDist;
          if (!pushed[u.b]){
            pushed[u.b] = 1;
            q.push(make_pair(newDist,u.b));
          }
        }
      }
    }
  }
}

int main(){
  /*cin.sync_with_stdio(0);
  cin.tie(0);*/

  //cin>>k>>n>>m;
  scanf("%d %d %d", &k,&n,&m);
  for(int i = 1; i <=m;i++){
    int a,b,t,h;
    //cin>>a>>b>>t>>h;
    scanf("%d %d %d %d", &a,&b,&t,&h);
    edges[a].PB(edg(b,t,h));
    edges[b].PB(edg(a,t,h));
  }
  int x,y;
  //cin>>x>>y;
  scanf("%d %d", &x, &y);
  dijkstra(x);
  int ans = INF;
  for(int i = 0; i <k;i++){
    //cout<<dist[y][i]<<" "<<i<<endl;
    ans = min(ans, dist[y][i]);
  }
  if(ans == INF){
    //cout<<-1<<endl;
    printf("%d", -1);
    return 0;
  }
  //cout<<ans<<endl;
  printf("%d", ans);
}
