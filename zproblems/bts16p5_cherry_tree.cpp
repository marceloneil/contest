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
//#define aall(x) x, x + n // #define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 100005

// this solution is incorrect. too lazy to debug

VPII edges[10005];
int cherries[10005];
int n,c,k,answer;

PII calc(int cur,int par){ // returns {#cherries, weight}
PII curAns = {cherries[cur], 0};
for(PII u : edges[cur]){
  if(u.F != par){
    PII ans = calc(u.F, cur);
    ans.S += u.S;
    if(ans.F >= c && ans.S <= k){
      answer++;
    }
    curAns.F +=ans.F;
    curAns.S +=ans.S;
  }
}
return curAns;
}

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  cin>>n>>c>>k;
  for(int i = 1;i<=n;i++){
    cin>>cherries[i];
  }
  for(int a = 1; a<n;a++){
    int x,y,z;
    cin>>x>>y>>z;
    edges[x].PB({y,z});
    edges[y].PB({x,z});
  }
  calc(1,-1);
  cout<<answer<<endl;
}
