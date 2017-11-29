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


int n,m;
vector<int> edges[100010];


int N, M, cIdx, cRoot, cnt, dfn[100010], low[100010];
bool vis[100010],alreadyPushed[100010];
vector<int> ans;

void tarjans(int u, int pre){
    low[u] = dfn[u] = cIdx++;
    vis[u] = 1;
    for(int v : edges[u]){
        if(!vis[v]) {
            if(cRoot == u) cnt++;
            tarjans(v, u);
            if(low[v] >= dfn[u] && !alreadyPushed[u]){
              alreadyPushed[u] = 1;
              ans.push_back(u);
            }
            low[u] = min(low[u], low[v]);
        }else if(v != pre){
          low[u] = min(low[u], dfn[v]);
        }
    }
}

struct greater1
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i =1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
    edges[b].PB(a);
  }
  for(int i =1 ; i <=n;i++){
    if(!vis[i]){
      tarjans(i,-1);
    }
  }
  cout<<++cnt + 1<<endl;
  sort(ans.begin(), ans.end(),greater1());
  while(!ans.empty()){
    cout<<ans.back()<<endl;
    ans.pop_back();
  }
}
