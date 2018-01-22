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


bool vis1[10005];
bool vis2[10005];
vector<int> edges[10005];
bool ans = 1;
void dfs(int start){
  vis1[start] = 1;
  vis2[start] = 1;
  for(int nd : edges[start]){
    if(vis2[nd]){
      ans = 0;
      return;
    }
    dfs(nd);
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin>>n>>m;
  for(int i = 1; i <=m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
  }
  for(int i = 1; i <=n;i++){
    if(!vis1[i]){
      memset(vis2,0,sizeof vis2);
      dfs(i);
    }
  }
  if(ans){
    cout<<"Y";
  }else{
    cout<<"N";
  }
}
