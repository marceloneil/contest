//the basic thing would be to do a bfs. But it's taking a really really long time. :/
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

int r,c,pr,pc,kr,kc;

int board[110][110];
queue<vector<int> > moves;
void bfs(int a,int b){
  vector<int> hi = {a,b,0};
  moves.push(hi);
  while(!moves.empty()){
    vector<int> temp = moves.front();moves.pop();
    int x = temp[0];
    int y = temp[1];
    int dist = temp[2];
    if(x < 1 || x > r || y < 1 || y > c) continue;
    if(board[x][y] != -1 && board[x][y] < dist) continue;
    board[x][y] = dist;
    hi = {x-1,y+2,dist+1};
    moves.push(hi);
    hi = {x+1,y+2,dist+1};
    moves.push(hi);
    hi = {x-1,y-2,dist+1};
    moves.push(hi);
    hi = {x+1,y-2,dist+1};
    moves.push(hi);

    hi = {x-2,y+1,dist+1};
    moves.push(hi);
    hi = {x-2,y-1,dist+1};
    moves.push(hi);
    hi = {x+2,y+1,dist+1};
    moves.push(hi);
    hi = {x+2,y-1,dist+1};
    moves.push(hi);
  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(board, -1, sizeof board);
  cin>>r>>c>>pr>>pc>>kr>>kc;
  bfs(kr,kc);
}
