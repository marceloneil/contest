#include <bits/stdc++.h>
using namespace std;

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
typedef vector<PII> VPII;
#define MAXN 100005

int tbit[MAXN], arr[MAXN];

void add(int* bit, int i, int val){
  while(i <= MAXN){
    bit[i] += val;
    i += (-i & i);
  }
}

int sum(int* bit, int i){
  int sum = 0;
  while(i > 0){
    sum += bit[i];
    i -= (i & -i);
  }
  return sum;
}

struct query{
  int l,r,m,o,a;
  query(int aa,int bb, int cc,int dd){
    l = aa;
    r = bb;
    m = cc;
    o = dd;
  }
  query();
};

struct tree{
  int x,m;
  tree(int xx, int cc){
    x = xx;
    m = cc;
  }
  tree();
};

bool compareByCost(const query &a, const query &b){
  return a.m < b.m;
}
bool compareByCost2(const tree &a, const tree &b){
  return a.m > b.m;
}


vector<query> queries;
vector<tree> trees;
int finalAns[100005];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n,q;
  cin>>n;
  for(int i =1;i<=n;i++){
    int temp;
    cin>>temp;
    trees.PB(tree(i,temp));
  }
  cin>>q;
  for(int i = 1; i<=q;i++){
    int a,b,c;
    cin>>a>>b>>c;
    queries.PB(query(a,b,c,i));
  }
  sort(vall(queries),compareByCost);
  sort(vall(trees),compareByCost2);
  int lastHeight = trees[0].m;
  for(int i = 0;i<n;i++){
    if(trees[i].m != lastHeight){
      lastHeight = trees[i-1].m;
      cout<<trees[i].m<<endl;
      while(queries.back().m >= trees[i].m){
        query hi = queries.back();
        queries.pop_back();
        finalAns[hi.o] = sum(tbit,hi.r) - sum(tbit,hi.l-1);
      }
    }
    add(tbit,trees[i].x,trees[i].m);
  }

  // I need to find some way to query for the last tree I add

  for(int i = 1; i<=n;i++){
    cout<<finalAns[i]<<endl;
  }
}
