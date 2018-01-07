#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
int inDegree[200005];
ll down[200005],up[200005];

ll dfs(ll *curArr,int cur, int par, ll dist) { // i = start, j = par, lvl = dist
	curArr[cur] = dist;
	ll ret = cur;
	ll max = dist;
	for (PII e : edges[cur]) {
		if (e.F != par) {
			ll alt = dfs(curArr ,e.F, cur, dist + e.S);
			if (curArr[alt] > max) {
				max = curArr[alt];
				ret = alt;
			}
		}
	}
	return ret;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  scan(n);
  scan(t);
  for(int i = 1; i <= n-1;i++){
    int a,b,c;
    scan(a);
    scan(b);
    scan(c);
    edges[a].PB({b,c});
    edges[b].PB({a,c});
    inDegree[a] += 1;
    inDegree[b] += 1;
    costOfTree+=c;
  }
  ll firstn = dfs(down,1,-1,0);
  memset(down, 0, sizeof down);
  ll secn = dfs(down,firstn,-1,0);
  dfs(up,secn,-1,0);

  costOfTree = costOfTree * 2;
  for(int i = 1; i <=n;i++){
    if(inDegree[i] == t){
      printf("%d %lld\n",i,costOfTree - max(down[i],up[i]));
    }
  }
}
