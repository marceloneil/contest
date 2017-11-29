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
  vis2[start] = 1;
  for(int nd : edges[start]){
    if(!vis2[nd]){
      dfs2(nd,dist+1);
    }
  }
}
//leaf1 and leaf 2 are the two diameters of the tree
