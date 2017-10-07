#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int N, Q;
struct node{
  int val = 0;
  int idx = 0;
};
node segtree[4 * MAXN];
int data[MAXN];

node maxNode(node a, node b){
  if(a.val > b.val){
    return a;
  }return b;
}

void build(int id, int left, int right){
    if (left == right){
        segtree[id].val = data[left];
        segtree[id].idx = left;
        return;
    }

    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);

    segtree[id].val = maxNode(segtree[id * 2], segtree[id * 2 + 1]).val;
    segtree[id].idx = maxNode(segtree[id * 2], segtree[id * 2 + 1]).idx;
}

void update(int id, int left, int right, int uid, int val){
    if (left == right){
        segtree[id].val = val;
        segtree[id].idx = left;
        return;
    }

    int mid = (left + right) / 2;

    if (uid <= mid){
        update(id * 2, left, mid, uid, val);
    } else {
        update(id * 2 + 1, mid + 1, right, uid, val);
    }

    segtree[id].val = maxNode(segtree[id * 2], segtree[id * 2 + 1]).val;
    segtree[id].idx = maxNode(segtree[id * 2], segtree[id * 2 + 1]).idx;
}

node query(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft){
      node hi;
      hi.val = 0;
      return hi;
    }
    if (qleft <= left && qright >= right) return segtree[id];

    int mid = (left + right) / 2;
    return maxNode(query(id * 2, left, mid, qleft, qright),
                query(id * 2 + 1, mid + 1, right, qleft, qright));
}

int main(){
    cin >> N >> Q;
    for (int i = 0; i < (2^N); i++){
      cin >> data[i];
    }

    build(1, 0, N - 1);
    cout<<"hi"<<endl;
    for (int i = 0; i < Q; i++){
        string cmd;
        int a, b;

        cin >> cmd;

        if (cmd == "R"){
          cin>>a>>b;
          update(1, 0, N - 1, a, b);
        } else if (cmd == "W"){
          cout << query(1, 0, N - 1, 0, N - 1).val << endl;
        }else{
          cin>>a;

          //cout << query(1, 0, N - 1, a, b) << endl;
        }
    }
    cout<<"wut"<<endl;
}
