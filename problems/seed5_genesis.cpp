#include <bits/stdc++.h>
using namespace std;

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

int arr[1005];
VPII edges[1005];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n,m;
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>arr[i];
  }
  cin>>m;
  for(int i = 1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
    edges[b].PB(a);
  }
   // ford fulkerson
   

}
