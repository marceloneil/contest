//for some reason this bfas takes foreverrrr :( rip)
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


int l,w,t;
int sx,sy,ex,ey;
int room[52][52];
int vis[52][52];

int bfs(int a,int b){
  queue<vector<int>> hi;
  vector<int> temp = {a,b,0};
  hi.push(temp);
  while(!hi.empty()){
    vector<int> s = hi.front();hi.pop();
    int x,y,d;
    x = s[0];
    y = s[1];
    d = s[2];
    if(x == ex && y == ey){
      room[x][y] = d;
      return 1;
    }
    if(room[x][y] == 0 && !vis[x][y]){
      if(d+1 == 60){
        return 2;
      }
      //cout<<"hi"<<endl;
      vis[x][y] = 1;
      room[x][y] = d;
      temp = {x+1,y,d+1};
      hi.push(temp);
      temp = {x-1,y,d+1};
      hi.push(temp);
      temp = {x,y+1,d+1};
      hi.push(temp);
      temp = {x,y-1,d+1};
      hi.push(temp);
    }
  }
  return 2;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--){
    memset(room,-1,sizeof room);
    memset(vis, 0, sizeof vis);
    cin>>w>>l;
    for(int a = 1; a<=l;a++){
      string hi;
      cin>>hi;
      for(int b = 1; b<=w;b++){
        if(hi.at(b-1) == 'X'){
          vis[a][b] = 1;
        }else if(hi.at(b-1) == 'O'){
          room[a][b] = 0;
        }else if(hi.at(b-1) == 'C'){
          room[a][b] = 0;
          sx = a;
          sy = b;
        }else if(hi.at(b-1) == 'W'){
          room[a][b] = 0;
          ex = a;
          ey = b;
        }
      }
    }
    int value = bfs(sx,sy);
    if(value == 1){
      cout<<room[ex][ey]<<endl;
    }else if(value == 2){
      cout<<"#notworth"<<endl;
    }
  }
}
