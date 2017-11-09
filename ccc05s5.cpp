#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 500000005
int tbit[MAXN], arr[MAXN];

template<class T> class fenwick_tree {
  int len;
  std::vector<int> a, bit;
public:
  fenwick_tree(int n): len(n),
  a(n + 1), bit(n + 1) {}
  //a[i] += v
  void add(int i, const T & v) {
    a[++i] += v;
    for (; i <= len; i += i & -i)
    bit[i] += v;
  }
  //a[i] = v
  void set(int i, const T & v) {
    T inc = v - a[i + 1];
    add(i, inc);
  }
  //returns sum(a[i] for i = 1..hi inclusive)
  T sum(int hi) {
    T res = 0;
    for (hi++; hi > 0; hi -= hi & -hi)
    res += bit[hi];
    return res;
  }
  //returns sum(a[i] for i = lo..hi inclusive)
  T sum(int lo, int hi) {
    return sum(hi) - sum(lo - 1);
  }
  inline int size() { return len; }
  inline T at(int i) { return a[i + 1]; }
};

fenwick_tree<int> t(MAXN);
int main(){
  int n,tot;
  tot = 0;
  scanf("%d",&n);
  for(int i = 1; i <= n;i++){
    scanf("%d", &arr[i]);
    t.add(arr[i],1);
    tot += i -t.sum(arr[i]) + 1;
  }
  printf("%.2f",round((100 * (double)(tot))/(double)n)/100 );
}
