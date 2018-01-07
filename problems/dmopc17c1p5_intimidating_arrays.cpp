#include <bits/stdc++.h>
using namespace std;

#define MN 100005
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
#define MAXN 1000005

int n, q;
int t[4 * MAXN], data[MAXN];

struct nd{
  int ans,low,high;
  nd();
};

void build(int id, int l, int r){
  if (l == r){
    t[id] = data[l];
    return;
  }

  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);

  t[id] = min(t[id * 2], t[id * 2 + 1]);
}

int query(int id, int l, int r, int ql, int qr){  // [l...r]
  if (l > qr || r < ql) return INF;
  if (ql <= l && qr >= r) return t[id];

  int mid = (l + r) / 2;
  return min(query(id * 2, l, mid, ql, qr),
  query(id * 2 + 1, mid + 1, r, ql, qr));
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> data[i];

  build(1, 0, n - 1);

  for (int i = 0; i < q; i++){
    int a, b;

    cin >> a >> b;
    cout << query(1, 0, n - 1, a, b) << endl;
  }
}
