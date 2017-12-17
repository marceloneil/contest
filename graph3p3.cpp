// lesson to be learned: WATCH OUT FOR THE ORDER IN WHICH YOU PUSH BACK INTO YOUR VECTORS
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

int lead[100005],setRank[100005];

int n,m;
void make_set(int p){
  lead[p] = p;
  setRank[p] = 1;
}
int find(int p){
  if(lead[p] == p) return p;
  lead[p] = find(lead[p]);
  return lead[p];
}

struct edge{
  int beg,end,c;
  bool d;
  edge(int bb,int ee,int cc, bool dd){
    beg = bb;
    end = ee;
    c = cc;
    d = dd;
  };
};

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
  for(int i = 1 ; i <=n;i++){
    make_set(i);
  }
}

bool compareByLength(const edge &a, const edge &b){ // comparing the struct
  return a.c > b.c;
}
int leng;
int numBad;
void kruskal(vector<edge> theEdges){
  int iterCount = 1;
  while(iterCount < n){
    if(theEdges.empty()){
      cout<<"Disconnected Graph"<<endl;
    }
    edge edg = theEdges.back();theEdges.pop_back();
    if(find(edg.beg) != find(edg.end)){
      leng+=edg.c;
      if(edg.d){
        numBad++;
      }
      //cout<<edg.beg<<" "<<edg.end<<endl;
      iterCount++;
      merge(edg.beg,edg.end);
    }
  }
}

vector<edge> edgesB;
vector<edge> edgesG;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  init();
  for(int i =1;i<=m;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d){
      edgesB.PB({a,b,c,d});
    }else{
      edgesG.PB({a,b,c,d});
    }
  }
  sort(vall(edgesB),compareByLength);
  sort(vall(edgesG),compareByLength);
  edgesB.insert( edgesB.end(), edgesG.begin(), edgesG.end() );
  for(int a = 3; a >=0;a--){
    //cout<<edgesB[a].c<<endl;
  }


  kruskal(edgesB);
  cout<<numBad<<" "<<leng<<endl;


}
