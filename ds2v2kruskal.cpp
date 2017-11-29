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

int n,m;

int lead[100005],setRank[100005];

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
struct edge{
  int cost,a,b;
  edge(int q, int w,int e){
    cost = q, a = w, b = e;
  }
};
//priority_queue<pair<int,pair<int,int> >, vector <pair<int,pair<int,int> >, greater<pair<int,pair<int,int> > > theEdges;
vector<pair<int,pair<int,int>>> theEdges;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1 ; i <=n;i++){
    make_set(i);
  }
  for(int i = 1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    theEdges.push_back({i,{a,b}});
  }
  int iterCount = 1;
  sort(theEdges.begin(), theEdges.end(),greater<pair<int,pair<int,int>>>());
  /*for(pair<int,pair<int,int>> aeg : theEdges){
    cout<<aeg.F<<" "<<aeg.S.F<<" "<<aeg.S.S<<endl;
  }*/
  stack<int> foundEdges;
  while(iterCount < n){
    if(theEdges.empty()){
      cout<<"Disconnected Graph"<<endl;
      return 0;
    }
    pair<int,pair<int,int>> edg = theEdges.back();theEdges.pop_back();
    //cout<<edg.F<<endl;
    if(find(edg.S.F) != find(edg.S.S)){
      iterCount++;
      merge(edg.S.F,edg.S.S);
      foundEdges.push(edg.F);
    }
  }
  while(!foundEdges.empty()){
    cout<<foundEdges.top()<<endl;
    foundEdges.pop();
  }
}
