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

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;
  int x1,y1,x2,y2,n;
  cin>>x1>>y1>>x2>>y2>>n;
  for(int i = 1; i<=n;i++){ // for each line in the form ax + by + c = 0
    int a,b,c;
    cin>>a>>b>>c; // think about this in the terms of innequalities
    // if the first point is one half of the plane
    // if the second point is on the same half of the plane
    // we'll either have -n*-n or n*n. therefore positive innequalities means both points are on the same side
    if((a*x1 + b*y1 + c)*(a*x2 + b*y2 + c) < 0) ans++;
  }
  cout<<ans<<endl;
}
