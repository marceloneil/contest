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

int n,t,costOfTree;
VPII edges[200005];
int inDegree[200005],down[200005],up[200005];

int dfsd(int cur,int par){
  int curDown = 0;
  for(PII e : edges[cur]){
    if(e.F != par){
      curDown = max(curDown, dfsd(e.F, cur) + e.S);
    }
  }
  return down[cur] = curDown;
}

int dfsu(int cur,int par){
  int curUp = 0;
  for(PII e : edges[cur]){
    if(e.F != par){
      up[e.F] = e.S + max(down[cur],)
      curDown = max(curDown, dfsd(e.F, cur) + e.S);
    }
  }
  return down[cur] = curDown;
}



int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  for(int i = 1; i <=t;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
    inDegree[a] += 1;
    inDegree[b] += 1;
    costOfTree+=c;
  }

  costOfTree = costOfTree * 2;
  for(int i = 1; i <=n;i++){
    if(inDegree[i] == t){
      cout<<costOfTree - max(down[i],up[i])<<endl;
    }
  }
}
