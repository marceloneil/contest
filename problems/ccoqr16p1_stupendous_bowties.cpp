#include <bits/stdc++.h>
using namespace std;

#define MN 100005
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

map<int,int> xcords;
map<int,int> ycords;
int x[100005],y[100005],xx[100005],yy[100005];
int ans = 0;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    int a,b;
    //cin>>x[i]>>y[i];
    cin>>a>>b;
    xx[i] = a;
    yy[i] = b;
    if(xcords.count(a) == 0){
      xcords[a] = i;
      x[xcords[a]] = 1;
    }else{
      x[xcords[a]]++;
    }
    if(ycords.count(b) == 0){
      ycords[b] = i;
      y[ycords[b]] = 1;
    }else{
      y[ycords[b]]++;
    }
  }
  for(int i = 1;i<=n;i++){
    if(x[xcords[xx[i]]] )
  }
}
