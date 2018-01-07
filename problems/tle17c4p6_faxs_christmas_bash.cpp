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

double arr[300005];
int n;

ll calc(double loc){
  ll ans = 0;
  for(int i = 1; i <=n;i++){
    ans+= pow(arr[i] - loc,3);
  }
  return ans;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>arr[i];
  }
  double hi = 15000;
  double lo = -15000;
  for(int i = 1; i <=50;i++){
    double q1 = lo + (hi-lo)/4;
    double q3 = lo + (hi-lo)*3/4;
    ll ans1 = calc(q1);
    ll ans2 = calc(q3);
    double mid = lo + (hi-lo)/2;
    if(ans1 < ans2){
      hi = mid;
    }else{
      lo = mid;
    }
  }
  printf("%f",lo + (hi-lo)/2);
}
