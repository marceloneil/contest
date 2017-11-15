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
#define ll long long
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int n,r,x,y;
vector<vector<int>> edges;
int rabbits[2005];
bool vis[2005];
int ans[2005];

int dfs(int start){
  vis[start] = 1;
  if(rabbits[start] == 1){
    ans[start] = 0;
    return 0;
  }
  int minDist = INF;
  for(int i = 1; i <=n;i++){
    if(!vis[i]){
      if(edges[start][i] == 1){
        minDist = min(minDist, dfs(i) + 1);
      }
    }
  }
  return minDist;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>r;
  for(int i = 1;i<n;i++){
    int a,b;
    cin>>a>>b;
    edges[a][b] = 1;
  }
  for(int i = 1; i <=r;i++){
    int r;
    cin>>r;
    rabbits[r] = 1;
  }
  cin>>x>>y;
  cout<<dfs(x)<<endl;
}
