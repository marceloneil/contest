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

int c,r,m,q,e;
ll graph[503][503],ans;
ll dist[503][503];
int sum[503][503];
ll maxDist = 0;
int maxWalk = 0;

struct nd{
  ll s;
  int l,x,y,w;
  nd(ll s1, int x1, int y1, int l1, int w1){
    s = s1; // sum of the distance walked
    x = x1; // x
    y = y1; // y
    l = l1; // value of last nd
    w = w1; // walk length
  };
};

void bfs(){
  stack<nd> theStack;
  theStack.push(nd(0,q,e,0,0));
  while(!theStack.empty()){
    nd t = theStack.top();theStack.pop();
    if(t.x < 1 || t.x >c || t.y < 1 || t.y > r)continue; // NOTE I MIGHT WANT TO SWITCH THE r AND c AROUND IN THIS STATEMENT
    if(graph[t.x][t.y] <= t.l) continue;
    if(dist[t.x][t.y] > t.w +1) continue;
    //if(sum[t.x][t.y] > t.s) continue;
    dist[t.x][t.y] = t.w + 1;
    if(t.w + 1> maxWalk){
      maxWalk = t.w + 1;
      maxDist = t.s + graph[t.x][t.y];
      //cout<<graph[t.x][t.y]<<" "<<t.x<<" "<<t.y<<endl;
    }else if(t.w + 1== maxWalk){
      maxDist = max(maxDist, t.s + graph[t.x][t.y]);
    }
    dist[t.x][t.y] = t.w;
    sum[t.x][t.y] = t.s;
    theStack.push(nd(t.s+ graph[t.x][t.y],t.x+1,t.y,graph[t.x][t.y], t.w + 1));
    theStack.push(nd(t.s+ graph[t.x][t.y],t.x-1,t.y,graph[t.x][t.y], t.w + 1));
    theStack.push(nd(t.s+ graph[t.x][t.y],t.x,t.y+1,graph[t.x][t.y], t.w + 1));
    theStack.push(nd(t.s+ graph[t.x][t.y],t.x,t.y-1,graph[t.x][t.y], t.w + 1));
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>c>>r>>m;
  for(int i = 1;i<=m;i++){
    int x,y,w,h,n;
    cin>>y>>x>>w>>h>>n;
    for(int a = 1; a<=h;a++){
      for(int b = 1; b <=w;b++){
        graph[a + x -1][b + y-1] = graph[a + x-1][b + y-1] + (a*b*n);
      }
    }
  }
  cin>>q>>e;
  bfs();
cout<<maxDist%1000000007<<endl;

/*
  cout<<endl;
  for(int i = 1;i<=r;i++){
    for(int a = 1;a<=c;a++){
      cout<<dist[i][a]<<" ";
    }
    cout<<endl;
  }*/
}
