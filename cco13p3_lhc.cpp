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

int n;
vector<int> edges[400005];

bool vis[400005];
int theMaxDist = -1;
int theNode = -1;
void dfs(int start, int dist){
  vis[start] = 1;
  if(dist > theMaxDist){
    theMaxDist = dist;
    theNode = start;
  }
  for(int nd : edges[start]){
    if(!vis[nd]){
      dfs(nd,dist+1);
    }
  }
}

int theNode2 = -1;
bool vis2[400005];
ll ansCount = 0;
ll theMaxDist2 = -1;
void dfs2(int start, int dist){
  vis2[start] = 1;
  if(dist == theMaxDist2){
    ansCount++;
  }else if(dist > theMaxDist2){
    theMaxDist2 = dist;
    ansCount = 1;
    theNode2 = start;
  }
  for(int nd : edges[start]){
    if(!vis2[nd]){
      dfs2(nd,dist+1);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i <n;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
    edges[b].PB(a);
  }
  dfs(1,0);
  dfs2(theNode,0);
  ll curAns1 = theMaxDist2;
  ll curAns2 = ansCount;
  memset(vis2, 0, sizeof vis2);
  ansCount = 0;
  theMaxDist2 = -1;
  dfs2(theNode2,0);
  if(ansCount > curAns2){
      cout<<theMaxDist2 + 1<<" "<<ansCount<<endl;
  }else{
    cout<<curAns1 + 1<<" "<<curAns2<<endl;
  }
}
