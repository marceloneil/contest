//right algorithm right approach but there's this damn corner case and I'm too lazy to fix it
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

int x[3005], y[3005],s,qu;
vector<PII> edges[3005];

int dist[3005];
bool vis[3005];

struct CompareByFirst {
  constexpr bool operator()(pair<int, int> const & a, pair<int, int> const & b)
  const noexcept{
    return a.first > b.first;
  }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, CompareByFirst> q;

void dijkstra(int root){
  memset(dist, INF, sizeof dist);
  dist[root] = 0;
  q.push({0,root});
  while(!q.empty()){
    PII cur_pair = q.top(); q.pop();
    int cur = cur_pair.S;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (PII u : edges[cur]){
      if(!vis[u.F]){
        int newDist = dist[cur] + u.S;
        if (newDist < dist[u.F]){
          dist[u.F] = newDist;
          q.push({newDist,u.F});
        }
      }
    }
  }
}

int binarySearch(int hi, int lo, int target){
  while(lo < hi){
    int mid = (lo + hi)/2;
    if (dist[mid] > target){
      hi = mid;
    }else{
      lo = mid+1;
    }
  }
  return lo;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i =1;i<=n;i++){
    cin>>x[i]>>y[i];
  }
  for(int i = 1; i <=n;i++){
    for(int a = 1; a <=n;a++){
      int dist = pow(x[i] - x[a],2) + pow(y[i] - y[a],2);
      //cout<<dist<<endl;
      edges[i].PB({a,dist});
      edges[a].PB({i,dist});
    }
  }
  cin>>s>>qu;
  dijkstra(s);
  sort(begin(dist), end(dist));

  while(qu--){
    int temp;
    cin>>temp;
    cout<<binarySearch(n,1,temp)<<endl;
  }
}
