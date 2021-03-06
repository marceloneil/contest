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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int t,n;
double x,y,r[105],c[105];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>t>>n;
  for(int i = 1; i < n;i++){
    cin>>r[i]>>c[i];
  }
  cin>>x>>y;
  double low = 0;
  double hi = t;
  int count = 14;
  while(count--){
    double mid = (hi-low)/2;
    int a = low + (mid/2);
    int b = hi-(mid/2);
    if((((t - a)/x) + (a/y)) < (((t - b)/x) + (b/y))){
      hi = mid;
      cout<<low<<" "<<hi<<endl;
      cout<<(((t - a)/x) + (a/y))<<endl;
    }else{
      cout<<low<<" "<<hi<<endl;
      cout<<(((t - b)/x) + (b/y))<<endl;
      low = mid;
    }
  }
  cout<< (low + (hi - low)/2)<<endl;
}
