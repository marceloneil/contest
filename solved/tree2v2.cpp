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


struct nd{
  int s,l,x,y,w;
  nd(ll s1, int x1, int y1, int w1){
    s = s1; // sum of the heights of trees chopped
    x = x1; // x
    y = y1; // y
    w = w1; // number of trees chopped
  };
};

int arr[14][14];
int tc[14][14]; // treesChopped
int hc[14][14]; // heightChopped
int w,e;
int maxOne = -1;
int c1 = -1;
int c2 = -1;
int r,c;


void bfs(){
  stack<nd> theStack;
  theStack.push(nd(0,w,e,0));
  while(!theStack.empty()){
    nd t = theStack.top(); theStack.pop();
    int ct; // cutTree
    if(arr[t.x][t.y] == 0){
      ct = 0;
    }else{
      ct = 1;
    }
    if(t.x < 1 || t.x >r || t.y < 1 || t.y > c)continue;
    if(hc[t.x][t.y] < t.s + arr[t.x][t.y]) continue;
    if(hc[t.x][t.y] == t.s + arr[t.x][t.y]){
      if(tc[t.x][t.y] <= t.w + ct) continue;
    }
    hc[t.x][t.y] = t.s + arr[t.x][t.y];
    tc[t.x][t.y] = t.w + ct;
    theStack.push(nd(hc[t.x][t.y], t.x+1,t.y,t.w+ct));
    theStack.push(nd(hc[t.x][t.y], t.x-1,t.y,t.w+ct));
    theStack.push(nd(hc[t.x][t.y], t.x,t.y+1,t.w+ct));
    theStack.push(nd(hc[t.x][t.y], t.x,t.y-1,t.w+ct));
  }
}


bool checkCloser(int a, int b){
  int dist1 = pow(c1 - w,2) + pow(c2-e,2);
  int dist2 = pow(a - w,2) + pow(b-e,2);
  if(dist2 < dist1){
    return true;
  }
  return false;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(tc,INF,sizeof tc);
  memset(hc,INF,sizeof hc);
  cin>>r>>c;
  for(int i = 1; i <=r;i++){
    for(int a = 1; a <=c;a++){
      string temp;
      cin>>temp;
      if(temp == "X"){
        w = i;
        e = a;
        arr[i][a] = 0;
      }else if(temp == "."){
        continue;
      }else{
        arr[i][a] = stoi(temp);
      }
    }
  }
  for(int i = 1; i <=r;i++){
    for(int a = 1; a <=c;a++){
      if(arr[i][a] == maxOne){
        if(c1 == -1 || checkCloser(i,a)){
          c1 = i;
          c2 = a;
          maxOne = arr[i][a];
        }
      }else if(arr[i][a] > maxOne){
        c1 = i;
        c2 = a;
        maxOne = arr[i][a];
      }
    }
  }
  bfs();
  cout<<tc[c1][c2]-1;
}
