#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

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
/*** Example Usage ***/
using namespace std;
int N,M,arr[MAXN];
fenwick_tree<LL> t(MAXN);
fenwick_tree<LL> t2(MAXN);
int main() {

  scanf("%d %d", &N, &M);
  for(int i = 1; i <=M;i++){
    scanf("%d", &arr[i]);
    t2.add(arr[i],1);
    t.set(i,arr[i]);
  }
  while(M--){
    char typeOfq;
    scanf("%s",&typeOfq);
    if(typeOfq == 'C'){
      int a,b;
      scanf("%d %d", &a,&b);
      t.set(a,b);
      t2.add(arr[a],-1);
      t2.add(b,1);
      arr[a] = b;
    }
    else if(typeOfq == 'S'){
      int a,b;
      scanf("%d %d", &a,&b);
      printf("%lld\n", t.sum(a,b));
    }
    if(typeOfq == 'Q'){
      int a;
      scanf("%d", &a);
      printf("%lld\n",t2.sum(0,a));
    }
  }
}
