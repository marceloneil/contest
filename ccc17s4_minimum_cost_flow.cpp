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

int n,m,d,ans;
struct edge{
  int st,end,c;
  bool a;
  edge(int ss, int bb, int cc, bool aa){
    st = ss;
    end = bb;
    c = cc;
    a = aa;
  };
};
vector<edge> edges; // b, cost, activated



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
  if (p != g){ // not in the same set
    if (setRank[p] > setRank[g]){ // marge the smaller set to the larger one
      lead[g] = p;
    }else{
      lead[p] = g;
      if (setRank[p] == setRank[g]) setRank[g]++;
    }
  }
}

bool compareByLength(const edge &a, const edge &b){
    return a.c < b.c;
}

void kruskal(vector<edge> theEdges){
  sort(theEdges.begin(), theEdges.end(),compareByLength);
  int iterCount = 0;
  for(int i = 0; US i < theEdges.size();i++){
    if(iterCount==n-1)break;
    edge edg = theEdges[i];
    if(find(edg.st) != find(edg.end)){
      if(edg.a == 0){ // right now I am turning on off pipes. I may need to turn off pipes that started out as on
        ans++;
      }
      iterCount++;
      merge(edg.st,edg.end);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>d;
  for(int i = 1 ; i <=n;i++){
    make_set(i);
  }
  for(int i = 1; i <=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(i<n){
      edges.PB(edge(a,b,c,1));
      edges.PB(edge(b,a,c,1));
    }else{
      edges.PB(edge(a,b,c,0));
      edges.PB(edge(b,a,c,0));
    }
  }
  kruskal(edges);

}
