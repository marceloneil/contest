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

// when I begin the line sweep and there's no rectangles there then I have to add the perimeter
VI xcords;
VI ycords;
map<int,int> xcordsa;
//map<int,int> ycordsb;
VPII scords;
VPII ecords;
int mapx[10005];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1; i<=n;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    xcords.PB(a);
    xcords.PB(c);
    scords.PB({a,b});
    ecords.PB({c,d});
    //ycords.PB(b);
    //ycords.PB(d);

  }
  sort(vall(xcords));
  //sort(vall(ycords));
  for(int i = 0;i<=n;i++){
    if(xcordsa.count(xcords[i]) == 0){
        xcordsa[xcords[i]] = i;
        mapx[i] = xcords[i];
    }
    //if(ycordsb.count(ycords[i]) == 0){
        //ycordsa[ycords[i]] = i;
    //}
  }

}
