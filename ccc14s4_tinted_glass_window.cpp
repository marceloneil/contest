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

struct panel{
  int x1,x2,y1,y2,t;
  panel(int a,int b, int c, int d, int tt){
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = d;
    t = tt;
  };
};

int n,t;
vector<int> xcoords;
vector<int> ycoords;
int diff[1005][1005];
int arr[1005][1005];
map<int,int> xmap;
map<int,int> ymap;
int xmap2[1005], ymap2[1005];
vector<panel> panels;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  for(int i = 1; i<=n;i++){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    xcoords.PB(a);
    ycoords.PB(b);
    xcoords.PB(c);
    ycoords.PB(d);
    panels.PB(panel(a,b,c,d,e));
  }
  sort(vall(xcoords));
  sort(vall(ycoords));
  for(int i = 0; i < 2*n;i++){
    xmap[xcoords[i]] = i+1;
    xmap2[i+1] = xcoords[i];
  }
  for(int i = 0; i < 2*n;i++){
    ymap[xcoords[i]] = i+1;
    ymap2[i+1] = xcoords[i];
  }
  for(panel u : panels){
    diff[xmap[u.x1]][ymap[u.y1]] += t;
    diff[xmap[u.x2]+1][ymap[u.y1]] -= t;
    diff[xmap[u.x1]][ymap[u.y2]+1] -= t;
    diff[xmap[u.x2]+1][ymap[u.y2]+1] += t;
  }
  int ans = 0;
  for(int i = 1;US i <= xmap.size();i++){
    for(int a = 1;US a <= ymap.size();a++){
      diff[i][a] += diff[i-1][a] + diff[i][a-1] - diff[i-1][a-1];
      cout<<diff[i][a]<<" ";
      if(diff[i][a] >=t){
        ans+= ((xmap2[i] - xmap2[i-1]) * (ymap2[a] - ymap2[a-1]));
      }
    }
    cout<<endl;
  }
  cout<<ans;
}
