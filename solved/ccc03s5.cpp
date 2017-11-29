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
#define ll long long
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;


//answer is the minimum of the maximum spanning tree between the destination cities and the starting city
int n,m,d,numCities,minimumWeight;

int lead[100005],setRank[100005],destination[10005];

void make_set(int p){
  lead[p] = p;
  setRank[p] = 1;
}
int find(int p){
  if(lead[p] == p) return p;
  lead[p] = find(lead[p]);
  return lead[p];
}
void merge(int p, int g){
  p = find(p);
  g = find(g);
  if (p != g){
    if (setRank[p] > setRank[g]) lead[g] = p;
    else{
      lead[p] = g;
      if (setRank[p] == setRank[g]) setRank[g]++;
    }
  }
}
vector<pair<int,pair<int,int>>> edges;

int kruskal(vector<pair<int,pair<int,int>> > theEdges){
  minimumWeight = 9999999;
  sort(theEdges.begin(), theEdges.end());
  int iterCount = 1;

  while(iterCount < n && numCities > 0){
    pair<int,pair<int,int>> edg = theEdges.back();theEdges.pop_back();
    if(find(edg.S.F) != find(edg.S.S)){
      if(destination[edg.S.F] == 1){
        destination[edg.S.F] = 0;
        numCities--;
      }
      if(destination[edg.S.S] == 1){
        destination[edg.S.S] = 0;
        numCities--;
      }
      iterCount++;
      merge(edg.S.F,edg.S.S);
      minimumWeight = min(minimumWeight, edg.F);
    }
  }
  return minimumWeight;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>d;
  for(int i = 1 ; i <=n;i++){
    make_set(i);
  }
  for(int i = 1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back({c,{a,b}});
  }
  numCities = d + 1;
  destination[1] = 1;
  for(int i = 1; i <=d;i++){
    int temp;
    cin>>temp;
    destination[temp] = 1;
  }
  cout<<kruskal(edges)<<endl;
}
