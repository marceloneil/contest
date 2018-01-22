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

VI edges[305];
bool type[305];
int diff[305];

int dfs(int cur, int par){
  int & ret = diff[cur];
  if(type[cur]){
    ret = 1;
  }else{
    ret = -1;
  }
    for(int u : edges[cur]){
      if(u != par){
        ret+= dfs(u,cur);
      }
    }
    return ret;
}

int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n,d;
  cin>>n>>d;
  for(int i = 1; i<=n;i++){
    int a,c;
    cin>>a>>type[a]>>c;
    for(int a = 1; a <=c;a++){
      int temp;
      cin>>temp;
      edges[a].PB(temp);
      edges[temp].PB(a);
    }
  }
  dfs(1,-1);
  for(int i = n; i>0;i--){
    diff[i] =
    // use a loop to add the answers of the previous things
  }
}
