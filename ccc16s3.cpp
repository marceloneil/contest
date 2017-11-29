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

vector<int> edges[100005];
bool isRest[100005];

int dp[100005];
bool vis1[100005];
bool vis2[100005];
int maxDist1 = -1;
int maxDist2 = -1;
int restRemaining1;
int restRemaining2;
int leaf1 = -1;
int leaf2 = -1;


void dfs1(int start,int dist){
  if(dist > maxDist1 && isRest[start]){
    maxDist1 = dist;
    leaf1 = start;
  }
  if(isRest[start]){
    restRemaining1--;
  }
  if(restRemaining1 == 0){
    return;
  }
  vis1[start] = 1;
  for(int nd : edges[start]){
    if(!vis1[nd]){
      dfs1(nd,dist+1);
    }
  }
}

void dfs2(int start,int dist){
  if(dist > maxDist2 && isRest[start]){
    maxDist2 = dist;
    leaf2 = start;
  }
  if(isRest[start]){
    restRemaining2--;
  }
  if(restRemaining2 == 0){
    return;
  }
  dp[start] = dist;
  vis2[start] = 1;
  for(int nd : edges[start]){
    if(!vis2[nd]){
      dfs2(nd,dist+1);
    }
  }
}

bool vis3[100005];
int dfs(int start, int dist){
  vis3[start] = 1;
  int totDist = 0;
  if(edges[start].size() > 2){
    int maxSideBranch = 0;
    for(int nd : edges[start]){
      if(!vis3[nd]){
        int ans = dfs(nd,dist+1);
        if(ans > maxSideBranch){
          totDist += maxSideBranch + ans;
          maxSideBranch = ans;
        }else{
          totDist+= (ans*2);
        }
      }
    }
  }else{
    for(int nd : edges[start]){
      if(!vis3[nd]) dfs(nd, dist + 1);
    }
  }
  if(isRest[start]) return (totDist + dist);
  return totDist;
}
stack<int> restaurants;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin>>n>>m;
  restRemaining1 = m;
  restRemaining2 = m;
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
  dfs1(restaurants.top(),0);
  dfs2(leaf1,0);
  //cout<<leaf1<<" "<<leaf2<<endl;
  cout<<dfs(leaf1,0)<<endl;
}
