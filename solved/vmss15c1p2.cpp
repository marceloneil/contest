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

int theMap[103][103];
int vis[103][103];
int ans = 0;

void dfs(int x,int y){
  if(theMap[x][y] == 0 || vis[x][y]) return;
  vis[x][y] = 1;
  dfs(x+1,y);
  dfs(x-1,y);
  dfs(x,y+1);
  dfs(x,y-1);
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int r,c;
  cin>>r>>c;
  for(int i = 1; i <=r;i++){
    string word;
    cin>>word;
    for(int a = 1; a<=c;a++){
      if(word.at(a-1) == '.'){
        theMap[i][a] = 1;
      }
    }
  }
  for(int i = 1;i<=r;i++){
    for(int a = 1; a<=c;a++){
      if(theMap[i][a] == 1 && !vis[i][a]){
        ans++;
        dfs(i,a);
      }
    }
  }
  cout<<ans<<endl;
}
