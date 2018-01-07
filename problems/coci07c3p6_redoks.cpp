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
#define MN 100005
//pretty ez v ez ezez ez. okay. just seg tree then mod ans by 9


int n,m;
int arr[250005];


#define MAX (1+(1<<20)) // Why? :D
#define inf 0x7fffffff

int tree[MAX];
int lazy[MAX];

void build(int nd, int a, int b) {
  if(a > b) return; // Out of range

  if(a == b) { // Leaf nd
    tree[nd] = arr[a]; // Init value
    return;
  }

  build(nd*2, a, (a+b)/2); // Init left child
  build(nd*2+1, 1+(a+b)/2, b); // Init right child

  tree[nd] = max(tree[nd*2], tree[nd*2+1]); // Init root value
}

void update(int nd, int a, int b, int i, int j, int value) {
  if(lazy[nd] != 0) { // This nd needs to be updated
    tree[nd] += lazy[nd]; // Update it

    if(a != b) {
      lazy[nd*2] += lazy[nd]; // Mark child as lazy
      lazy[nd*2+1] += lazy[nd]; // Mark child as lazy
    }

    lazy[nd] = 0; // Reset it
  }

  if(a > b || a > j || b < i) return; // seg not in range

  if(a >= i && b <= j) { // Segment is fully within range
    tree[nd] += value;
    if(a != b) { // not leaf nd
      lazy[nd*2] += value;
      lazy[nd*2+1] += value;
    }
    return;
  }

  update(nd*2, a, (a+b)/2, i, j, value); // Updating left child
  update(1+nd*2, 1+(a+b)/2, b, i, j, value); // Updating right child

  tree[nd] = max(tree[nd*2], tree[nd*2+1]); // Updating root with max value
}
void addr(int l, int r, int val){
  update(1, 0, n-1,l,r,val);
}

/**
* Query tree to get max element value within range [i, j]
*/
int query(int nd, int a, int b, int i, int j) {

  if(a > b || a > j || b < i) return -inf; // Out of range

  if(lazy[nd] != 0) { // This nd needs to be updated
    tree[nd] += lazy[nd]; // Update it

    if(a != b) {
      lazy[nd*2] += lazy[nd]; // Mark child as lazy
      lazy[nd*2+1] += lazy[nd]; // Mark child as lazy
    }

    lazy[nd] = 0; // Reset it
  }

  if(a >= i && b <= j) // Current segment is totally within range [i, j]
  return tree[nd];

  int q1 = query(nd*2, a, (a+b)/2, i, j); // Query left child
  int q2 = query(1+nd*2, 1+(a+b)/2, b, i, j); // Query right child

  int res = max(q1, q2); // Return final result

  return res;
}

int maxr(int l, int r){
  return query(1, 0, n-1,l,r);
}


int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  string nums;
  cin>>nums;
  for(int i = 0;i<n;i++){
    arr[i] = nums.at(i) - '0';
  }

  build(1, 0, n-1);
  memset(lazy, 0, sizeof lazy);
  for(int i = 1; i<=m;i++){
    int a,b;
    cin>>a>>b;
    addr(a,b,1);
  }
  cout<<"hji"<<endl;
  cout<<maxr(0,n-1)<<endl;
}
