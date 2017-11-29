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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int theMap[105][105];
bool important[105][105];
int w,c,r;

int ans;
void spill(int x,int y){
  cout<<x<<" "<<y<<endl;
  if(theMap[x][y+1] == 1 || y+1 > r){
    if(theMap[x+1][y] == 1 || x+1 > c){
      theMap[x][y] = 1;
      if(important[x][y] == 1){
        ans++;
      }
    }else{
      spill(x+1,y);
    }
  }else{
    spill(x,y+1);
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>w>>c>>r;
  for(int i = 1; i <=r;i++){
    string row;
    cin>>row;
    for(int a = 1; a <=c;a++){
      if(row[a-1] == '#'){
        theMap[i][a] = 1;
      }else if(row[a-1] == 'A'){
        important[i][a] = 1;
      }
    }
  }
  while(w--){
    spill(1,1);
  }
  cout<<ans<<endl;
  for(int i = 1; i <=r;i++){
    for(int a = 1; a <=c;a++){
      cout<<theMap[i][a];
    }
    cout<<endl;
  }
}
