
#include <bits/stdc++.h>

#define MAXN 100001
#define INF 0x3f3f3f3f

using namespace std;

int n, q;
int t[4 * MAXN], data[MAXN];

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

void update(int id, int l, int r, int uid, int val){ // [l...r]
  if (l == r){
    t[id] = val;
    return;
  }

  int mid = (l + r) / 2;

  if (uid <= mid){
    update(id * 2, l, mid, uid, val);
  } else {
    update(id * 2 + 1, mid + 1, r, uid, val);
  }

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
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> data[i];

  build(1, 0, n - 1);

  for (int i = 0; i < q; i++){
    string cmd;
    int a, b;

    cin >> cmd >> a >> b;

    if (cmd == "Q"){
      cout << query(1, 0, n - 1, a, b) << endl;
    } else {
      update(1, 0, n - 1, a, b);
    }
  }
}
