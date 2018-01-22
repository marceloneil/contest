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



struct plant{
  int l,r,h;
  plant(int lle, int rr, int hh){
    l = lle;
    r = rr;
    h = hh;
  }
};
bool compareByCost(const plant &a, const plant &b){
  return a.l < b.l;
}
bool horzLinesAtY[1000];
vector<plant> plants;
int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i<=n;i++){
    int a,b;
    cin>>a>>b;
    plants.PB(plant(a,b,i));
  }
  sort(vall(plants),compareByCost);
  for(int i =0;i<n;i++){
    horzLinesAtY[plants[i].l] = 1;
    int curHorzLines = 0;
    for(int a = 1;i<=plants[a].h;a++){
      if(horzLinesAtY[a] == 1) curHorzLines++;
    } 
  }
}
