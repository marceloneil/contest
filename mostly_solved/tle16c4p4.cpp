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

int n,m,q;
vector<pair<int,int>> edges[100003];
bool vis[100003];
bool vis2[100003];
bool vis3[100003];
ll furthest[100003];

ll maxDist,theMax,minRad;
int leaf1,leaf2;

void dfs(int start, ll dist){
  if(dist > maxDist){
    maxDist = dist;
    leaf1 = start;
  }

  vis[start] = 1;
  for(pair<int,int> nd : edges[start]){
    if(!vis[nd.F]){
      dfs(nd.F,dist + nd.S);
    }
  }
}

void dfs2(int start,ll dist){
  if(dist > maxDist){
    maxDist = dist;
    leaf2 = start;
  }

  vis2[start] = 1;
  for(pair<int,int> nd : edges[start]){
    if(!vis2[nd.F]){
      furthest[nd.F] = dist + nd.S;
      dfs2(nd.F,dist + nd.S);
    }
  }
}

void dfs3(int start,ll dist){
  //cout<<minRad<<endl;
  ll temp = max(dist,furthest[start]);
  if(temp < minRad){
    minRad = temp;
  }

  vis3[start] = 1;
  for(pair<int,int> nd : edges[start]){
    if(!vis3[nd.F]){
      dfs3(nd.F,dist + nd.S);
    }
  }
}

int increaseByOne = 0;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int sectionsFound = 0;
  cin>>n>>m>>q;
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a].push_back({b,c});
    edges[b].push_back({a,c});
  }
  if(q == 1){
    for(int i = 1; i <=n;i++){
      maxDist = -1;
      if(!vis[i]){
        sectionsFound++;
        dfs(i,0);
        dfs2(leaf1,0);
        theMax += maxDist;
      }
    }
    cout<<theMax + (sectionsFound-1)<<endl;
  }else{
    if(m == 0){
      cout<<1<<endl;
      return 0;
    }
    for(int i = 1; i <=n;i++){
      maxDist = -1;
      minRad = INF;
      if(!vis[i]){
        //sectionsFound++;
        if(edges[i].size() == 0){
          continue;
        }
        if(edges[i].size() == 1){
          //if it is a system of two nodes then the max radius is the length of that one edge
          ll temp = edges[i][0].S;
          theMax = max(theMax,temp);
          /*if(temp == theMax){
            increaseByOne = 1;
            continue;
          }
          if(temp > theMax){
            increaseByOne = 0;
            theMax = temp;
          }*/
          continue;
        }
        dfs(i,0);
        dfs2(leaf1,0);
        dfs3(leaf2,0);
        if(minRad == theMax){ // this means that the two trees are the same height and a connecting bridge bw the
          //two trees will increase the radius by 1
          increaseByOne = 1;
          continue;
        }
        if(minRad > theMax){
          increaseByOne = 0;
          theMax = minRad;
        }
      }
    }
    if(theMax == 0){
      cout<<1;
      return 0;
    }
    cout<<theMax + increaseByOne;
  }
}
