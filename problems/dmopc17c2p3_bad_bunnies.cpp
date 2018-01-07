//here's how I did it:
// 1) find all the edges that makes up the shortest path to the exit
// 2) add those edges to a stack
// 3) pop off those edges and look at the nodes attached
// 4) seperate all the edges that leads to another node for every node
// 5) do a dfs on each node but don't dfs on the edges that are part of the minimum exit path
// 6) this second dfs will find the closest rabbits

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

int n,r,x,y;
vector<int> edges[200005];
vector<int> edges2[200005];
int rabbits[200005];
bool vis[200005];
bool vis2[200005];
bool noEdges[200005];

stack<int> landedNodes;
int dfs(int start){
  if(start == y)return 0;
  vis[start] = 1;
  for(int nd: edges[start]){
    if(!vis[nd]){
      int foundAns = dfs(nd);
      if(foundAns > -1){
        landedNodes.push(nd);
        edges2[nd].PB(start);
        edges2[start].PB(nd);
        return 0;
      }
    }
  }
  return -1;
}

int masterAns = INF;
void dfs2(int start, int dist){
  vis2[start] = 1;
  if(rabbits[start] == 1){
    masterAns = min(masterAns,dist);
  }
  for(int nd: edges[start]){
    if(!noEdges[nd]){
      if(!vis2[nd]){
        dfs2(nd,dist+1);
      }
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>r;
  for(int i = 1;i<n;i++){
    int a,b;
    cin>>a>>b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <=r;i++){
    int r;
    cin>>r;
    rabbits[r] = 1;
  }
  cin>>x>>y;
  dfs(x);
  int curNode = x;
  landedNodes.push(curNode);
  while(!landedNodes.empty()){
    curNode = landedNodes.top(); landedNodes.pop();
    for(int nd : edges2[curNode]){
      noEdges[nd] = 1;
    }
    dfs2(curNode,0);
    for(int nd : edges2[curNode]){
      noEdges[nd] = 0;
    }
  }
 cout<<masterAns<<endl;
}
