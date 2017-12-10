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

int n,m;
vector<int> edges[100005];
bool isRest[100005];

vector<int> edges2[100005];
int theCount = 0;

bool vis[100005];
bool vis2[100005];
int dfs(int start){
  int ans = 0;
  vis[start] = 1;
  for(int nd : edges[start]){
    if(!vis[nd]){
      ans = dfs(nd);
      if(ans > 0){
        edges2[start].push_back(nd);
        edges2[nd].push_back(start);
        theCount++;
      }
    }
  }
  if(isRest[start]) ans = 1;
  return ans;
}

pair<int,int> dfs2(int start, int dist){ // returns dist, nodeIdx
  vis2[start] = 1;
  int maxDist = dist;
  int maxIdx = start;
  for(int nd : edges2[start]){
    if(!vis2[nd]){
      pair<int,int> temp = dfs2(nd,dist+1);
      if(temp.F > maxDist){
        maxDist = temp.F;
        maxIdx = temp.S;
      }
    }
  }
  return {maxDist,maxIdx};
}



int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin>>n>>m;
  stack<int> restaurants;
  for(int i =1;i<=m;i++){
    int temp;
    cin>>temp;
    isRest[temp] = 1;
    restaurants.push(temp);
  }
  for(int i = 1;i<n;i++){
    int a,b;
    cin>>a>>b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfs(restaurants.top());
  int firstIdx = dfs2(restaurants.top(),0).S;
  memset(vis2, 0,sizeof vis2);
  cout<<((theCount*2) - dfs2(firstIdx,0).F)<<endl;  
}
