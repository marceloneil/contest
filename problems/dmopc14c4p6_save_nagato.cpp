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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

VI edges[500005];
map<string,int> memo;
int ccount(int cur, int par,int dist){
  if(memo.count(to_string(cur) + "," + to_string(par))){
    return memo[to_string(cur) + "," + to_string(par)];
  }
  int maxCur = 0;
  for(int i : edges[cur]){
    if(i!=par){
      maxCur = max(maxCur, ccount(i,cur,1));
    }
  }
  return memo[to_string(cur) + "," + to_string(par)] = maxCur + dist;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin>>n;
  for(int i = 1; i<n;i++){
    int a,b;
    cin>>a>>b;
    edges[b].PB(a);
    edges[a].PB(b);
  }
  for(int i = 1;i<=n;i++){
    printf("%d\n",ccount(i,-1,1));
  }
}
