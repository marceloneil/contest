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

int x[12],y[12];
ll maxDist = -INF;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>x[i]>>y[i];
  }
  for(int i = 1 ;i<=n;i++){
    for(int a = i+1; a <=n;a++){
      maxDist = max(maxDist, (long long) (pow(x[a]-x[i],2) + pow(y[a]-y[i],2)));
    }
  }
  //DON'T FORGET TO ROUND
  printf("%.2lf", roundf(sqrt(maxDist)*100)/100);
}
