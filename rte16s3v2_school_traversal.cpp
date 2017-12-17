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

vector<PII> edges[6005];
int dist[6005][6005];

int start, ans;

void dfs(int cur,int last, int diste){
  dist[start][cur] = diste;
  dist[cur][start] = diste;
  for(PII e : edges[cur]){
    if(e.F !=last){
      dfs(e.F,cur, diste + e.S);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,q;
  cin>>n;
  for(int i = 1; i <n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }

  for(int i = 0; i <=n;i++){
    start = i;
    dfs(i,-1,0);
  }

  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<dist[a][b]<<endl;
  }
}
