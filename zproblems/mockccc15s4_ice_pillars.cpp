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

int w[100005], d[100005];

// this is hyperfax cancer
PII dp[100005][100005];
PII calc(int l,int r,int dir, int d){ // direction of damage, damage amount
  if(l == r){
    int ans = d[l] - d;
    if(ans < 0) ans = 0;
    return dp[l][r] = {ans,ans};
  }

}

int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i<=n;i++){
    cin>>w[i]>>d[i];
  }


}
