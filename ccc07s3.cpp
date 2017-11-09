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

vector<int> hi[10005];
int vis[10005];
vector<pair<int,int>>  theq;
int bfs(int a,int b){
  for(int i = 0;US i < sizeof hi[a];i++){
    theq.push_back(make_pair(hi[a][i],0));
  }
  while(!theq.empty()){
    PII val = theq.back();theq.pop_back();
    vis[val.F] = 1;
    for(int c : hi[val.F]){
      if(val.F == b){
        return val.S;
      }
      if(!vis[c]){
        theq.push_back(make_pair(c,val.S + 1));
      }
    }
  }
  return -1;
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1;i<=n;i++){
    int x,y;
    scanf("%d %d", &x,&y);
    hi[x].push_back(y);
  }
  int a,b;
  scanf("%d %d", &a,&b);
  while(a != 0 && b != 0){
    memset(vis,0,sizeof vis);
    int ans = bfs(a,b);
    if(ans == -1){
      printf("%s\n","No");
    }else{
      printf("%s %d","Yes",ans);
    }
    scanf("%d %d", &a,&b);
  }
}
