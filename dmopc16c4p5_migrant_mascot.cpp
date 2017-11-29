//the kruskal strat is good but I'm implementing this poorly

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
vector<pair<int,pair<int,int>>> edges;

stack<int> kruskal(vector<pair<int,pair<int,int>> > theEdges){
  sort(theEdges.begin(), theEdges.end(),greater<pair<int,pair<int,int>>>());
  int iterCount = 1;
  stack<int> temp;

  while(iterCount < n){
    if(theEdges.empty()){
      cout<<"Disconnected Graph"<<endl;
      return stack<int>();
    }
    pair<int,pair<int,int>> edg = theEdges.back();theEdges.pop_back();
    if(find(edg.S.F) != find(edg.S.S)){
      iterCount++;
      merge(edg.S.F,edg.S.S);
      temp.push(edg.F);
    }
  }
  return temp;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  REP(i,1,n){
    make_set(i);
  }
  REP(i,1,m){
    int a,b,c;
    cin>>a>>b>>c;
    edges.PB({c,{a,b}});
    //edges.PB({c,{b,a}});
  }
  stack<int> mstEdges = kruskal(edges);
  while(!mstEdges.empty()){
    cout<<mstEdges.top()<<endl;
    mstEdges.pop();
  }
}
