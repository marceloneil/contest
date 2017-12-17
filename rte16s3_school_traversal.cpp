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


int lookup[3005][6005];
void build(int A[6005], int n) {

    int h = floor(log2(n));

    // base case
    for (int j = 0; j < n; j++) lookup[0][j] = A[j];

    // iterative dynamic programming approach
    for (int i = 1; i <= h; i++)
        for (int j = 0; j + (1<<i) <= n; j++)
            lookup[i][j] = min(lookup[i-1][j], lookup[i-1][j + (1<<(i-1))]);
}

int query(int l, int r) {// THIS IS IMPORTANT: query in range [l,r)
    int p = 31 - __builtin_clz(r-l);
    return min(lookup[p][l], lookup[p][r-(1<<p)]);
}

int main(){
  build(arr,6);
  //query in range [l,r)
  printf("%d",query(4,6));
}




vector<PII> edges[6005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,qu;
  cin>>n;
  for(int i = 1; i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].PB({b,c});
    edges[b].PB({a,c});
  }
  cin>>qu;
  while(qu--){
    int x,y;
    cin>>x>>y;

  }
}
