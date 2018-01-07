//I really think my solution is correct but I'm still somehow printing a negative number... which makes no sense

#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
typedef vector<PII> VPII;
#define MN 100005

VPII edges[500005];
VPII edges2[500005];
set<int> camps;
set<int> smallCamps;
int treesize = 0;

int dfs(int cur, int par){ // used to find the mst for nodes I need to visit
  int ans = -1;
  if(camps.count(cur) > 0){
    ans = 0;
  }
  for(PII nd: edges[cur]){
    if(nd.F != par){
      int foundAns = dfs(nd.F,cur);
      if(foundAns > -1){
        treesize+=nd.S;
        smallCamps.insert(nd.F);
        edges2[nd.F].PB({cur,nd.S});
        edges2[cur].PB(nd);
        ans = 0;
      }
    }
  }
  return ans;
}
ll dist0[500005];
ll dist1[500005];
ll dist2[500005];

//simpler version:
int nodeDist(ll *curArr, int cur, int par, ll dist) {
	curArr[cur] = dist;
	ll ret = cur;
	ll max = dist;
	for (PII e : edges2[cur]) {
		if (e.F != par) {
			ll alt = nodeDist(curArr ,e.F, cur, dist + e.S);
			if (curArr[alt] > max) {
				max = curArr[alt];
				ret = alt;
			}
		}
	}
	return ret;
}

ll findSmallerTree(int cur, int par,ll dist){ // I technically don't need to pass dist
  if(smallCamps.count(cur) > 0 || camps.count(cur) > 0){
    return dist + treesize*2 - max(dist1[cur],dist2[cur]);
  }
  for(PII nd: edges[cur]){
    if(nd.F != par){
      ll ans1 = findSmallerTree(nd.F,cur,dist + nd.S);
      if(ans1 > 0) return ans1;
    }
  }
  return 0;
}

int main(){
  int n,k;
  scan(n);scan(k);
  for(int i = 1; i<n;i++){
    int a,b,c;
    scan(a);scan(b);scan(c);
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }
  for(int i = 1; i<=k;i++){
    int temp;
    scan(temp);
    camps.insert(temp);
  }
  dfs(*camps.begin(),-1);
  int one = nodeDist(dist0,*camps.begin(),-1,0);
  int second = nodeDist(dist1,one,-1,0);
  nodeDist(dist2,second,-1,0);
  for(int i = 1; i<=n;i++){
    printf("%lld\n",findSmallerTree(i,-1,0));
  }
}
