#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

double family[10005][4];
//0 = m
//1 = b
//2 = x1
//3 = y1
int main(){
  //this algorithmn is a bust because it doesn't take into account the flock's speed
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,r;
  cin>>n>>r;
  for(int i = 1; i <=n;i++){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double m;
    if(x2-x1 == 0){
      m = 999999;
    }else{
      m = (y2-y1)/(x2-x1);
    }
    double b = y2-(m*x2);
    family[i][0] = m;
    family[i][1] = b;
    family[i][2] = x1;
    family[i][3] = y1;
  }
  for(int i = 2; i<=n;i++){
    double m = family[1][0];
    double b = family[1][1];
    double x1 = family[1][2];
    double x2 = family[1][3];

    double 2m = family[i][0];
    double 2b = family[i][1];
    double 2x1 = family[i][2];
    double 2x2 = family[i][3];
    if(m == 2m){

    }
  }
  //y=mx+b
  //mx+b = mx+b
  //
}
