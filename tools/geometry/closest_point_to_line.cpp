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

  int x1,y1,x2,y2,x3,y3;
  // points 1 and 2 form a straight line
  // point 3 is perpendicular to this line
  double m1 = (y2-y1)/(x2-x1);
  double m3 = -1/m1;
  double b1 = y1-m1*x1;
  double b3 = y3-m3*x3;
  // now solve the linear equation
  double x4 = (b3-b1)/(m1-m3);
  double y4 = m1*x4 + b1;
}
