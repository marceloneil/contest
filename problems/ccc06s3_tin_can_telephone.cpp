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


bool onSegment(PII p, PII q, PII r){
  if (q.F <= max(p.F, r.F) && q.F >= min(p.F, r.F) &&
  q.S <= max(p.S, r.S) && q.S >= min(p.S, r.S))
  return true;
  return false;
}

int orientation(PII p, PII q, PII r){
  int val = (q.S - p.S) * (r.F - q.F) - (q.F - p.F) * (r.S - q.S);
  if (val == 0) return 0;  // colinear
  return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(PII p1, PII q1, PII p2, PII q2){
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
  return true;

  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  return false; // Doesn't fall in any of the above cases
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  int x1,yy1,x2,y2,n;
  cin>>x1>>yy1>>x2>>y2>>n;

  for(int u = 1;u<=n;u++){
    int p;
    cin>>p;
    VI xCords;
    VI yCords;
    for(int i = 1; i <=p;i++){
      int a,b;
      cin>>a>>b;
      xCords.PB(a);
      yCords.PB(b);
    }
    if(doIntersect({x1,yy1},{x2,y2},{xCords[0],yCords[0]},{xCords[p-1], yCords[p-1]})){
      ans++;
    }else{
      for(int i = 0; i < p-1;i++){
        if(doIntersect({x1,yy1},{x2,y2},{xCords[i],yCords[i]},{xCords[i+1], yCords[i+1]})){
          ans++;
          break;
        }
      }
    }
  }
  cout<<ans<<endl;
}
