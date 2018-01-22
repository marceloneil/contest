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


// looked at the question for 5 seconds and legit found the answer
// so crappy. You have to find the two furthest points
// then you have to rotate all the points so those 2 points are parallel to the x-axis
// then find the minimum rectangle to enclose all those points.

// on second thought maybe not hte 2 furthest points. But ik you have to rotate it.

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
}
