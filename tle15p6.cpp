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

int n,m,q,visited[5005];
vector<int> wins[5005];

int dfs(int a,int b){

}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>q;
  while(m--){
    int a,b;
    cin>>a>>b;
    wins[a].push_back(b);
  }
  while(q--){
    memset(visited,0,sizeof visited);
    int a,b;
    cin>>a>>b;
    dfs(a,b);
    win
  }
}
