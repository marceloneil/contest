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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

int n,m,lead[100005],setRank[100005];
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
void init(){ // DO NOT FORGET THIS PLEASE
  for(int i = 1 ; i <=n;i++) make_set(i);
}

struct edge{
  int beg,end,c;
  edge(int a,int b,int cc){
    beg = a;
    end = b;
    c = cc;
  };
};

bool compareByCost(const edge &a, const edge &b){
  return a.c > b.c;
}

vector<edge> theEdges;
vector<edge> newEdges;

void kruskal(vector<pair<int,pair<int,int>> > theEdges){
  sort(theEdges.begin(), theEdges.end(),greater<pair<int,pair<int,int>>>());
  int iterCount = 1;
  while(iterCount < n){
    if(theEdges.empty()){
      cout<<"Disconnected Graph"<<endl;
    }
    pair<int,pair<int,int>> edg = theEdges.back();theEdges.pop_back();
    if(find(edg.S.F) != find(edg.S.S)){
      iterCount++;
      merge(edg.S.F,edg.S.S);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  init(); // DO NOT FORGET THIS LINE
  for(int i = 1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    theEdges.push_back(edge(a,b,c));
  }
  //kruskal
  sort(theEdges.begin(), theEdges.end(),compareByCost);
  int iterCount = 1;
  while(iterCount < n){
    edge edg = theEdges.back();theEdges.pop_back();
    if(find(edg.beg) != find(edg.end)){
      iterCount++;
      merge(edg.beg,edg.end);
      newEdges.PB(edg);
    }
  }
  //printing out newEdges
  while(!newEdges.empty()){
    cout<<newEdges.back().c<<endl;newEdges.pop_back();
  }
}
