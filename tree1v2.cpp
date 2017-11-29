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

bool arr[6][6];
bool edges[6][6];
bool vis[6];
bool ans = 1;

void dfs(int a){
  vis[a] = 1;
  for(int i = 1 ; i <=4;i++){
    if(!edges[a][i] && vis[i]){
      ans = 0;
    }
    if(!vis[i] && arr[a][i]){
      edges[i][a] = 1;
      edges[a][i] = 1;
      dfs(i);
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 1; i <=4;i++){
    for(int a = 1; a <=4;a++){
      bool temp;
      cin>>temp;
      edges[i][a] = temp;
      arr[i][a] = temp;
    }
  }
  dfs(1);
  if(ans){
    cout<<"Yes";
    return 0;
  }
  cout<<"No";
}
