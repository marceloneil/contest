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

int n,m,d;
struct nxt{
  int b,c;
  bool a;
  nxt(int bb, int cc, bool aa){
    b = bb;
    c = cc;
    a = aa;
  }
};
vector<nxt> edges[100003]; // b, cost, activated



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
  cin>>n>>m>>d;
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(i <n){
      edges[a].PB(nxt(b,c,1));
      edges[b].PB(nxt(a,c,1));
    }else{
      edges[a].PB(nxt(b,c,0));
      edges[b].PB(nxt(a,c,0));
    }
  }
}
