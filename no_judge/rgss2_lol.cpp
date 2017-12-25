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

  int n;
  cin>>n;
  int max1 = -INF;
  int max2 = -INF;
  int max3 = INF;
  int max4 = INF;

  for(int i = 1; i<=n;i++){
    int a,b;
    cin>>a>>b;
    max1 = max(max1,a);
    max2 = max(max2,b);
    max3 = min(max3,a);
    max4 = min(max4,b);
  }
  cout<<(max1-max3)*(max2-max4)<<endl;
}
