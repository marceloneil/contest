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

#define ll long long
//note use long long for the final ans
int value[200005];
int alreadyDfs[200005];
vector<int> edges[200005];
int indegree[200005];
bool vis[200005];
ll ans = 0;
int n;

queue<int> topsort(){
  queue<int> Q;
  for(int i = 1; i<=n;i++){
    if(indegree[i] == 1 ){
      Q.push(i);
    }
  }
  queue<int> finalQueue;
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    finalQueue.push(v);
    for(int nd: edges[v]){
      if( --indegree[nd] == 1 ){
        Q.push(nd);
      }
    }
  }
  return finalQueue;
}

void dfs(int node, int dist,int val){
  vis[node] = 1;
  ans+= dist*(val + value[node]);
  for(int nd : edges[node]){
    if(!vis[nd] && !alreadyDfs[nd]){
      dfs(nd, dist+1,val + value[node]);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>value[i];
  }
  for(int i = 1; i<n;i++){
    int a,b;
    cin>>a>>b;
    edges[a].push_back(b);
    edges[b].push_back(a);
    indegree[b]+=1;
    indegree[a]+=1;
  }
  queue<int> finalQueue = topsort();
  while(!finalQueue.empty()){
    memset(vis, 0, sizeof vis);
    int tVal = finalQueue.front();
    dfs(tVal,0,0);
    finalQueue.pop();
    vector<int> tEmpty;
    //remove the node from the graph because all paths to this node will be a repeat.
    alreadyDfs[tVal] = 1;
  }
  cout<<ans<<endl;
}
