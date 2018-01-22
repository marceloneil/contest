
#include <bits/stdc++.h>

#define MAXN 100001
#define INF 0x3f3f3f3f

using namespace std;

int N, Q;

struct node{
  int mini;
  int gcd;
  map<int,int> nums;
};

node segtree[4 * MAXN];
int data[MAXN];

int gcd(int a, int b){
  if (a == INF){
    return b;
  }else if(b == INF){
    return a;
  }else if (a == 0 || b == 0){
    return 0;
  }else if (a == b){
    return a;
  }else if (a > b){
    return gcd(a-b, b);
  }
  return gcd(a, b-a);
}

/*int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return gcd(b, a%b);
}*/

map<int,int> merge(node a, node b){
  map<int,int> newm;
	// Iterate over the map using Iterator till end.
  for(pair<int,int> val : a.nums){
    newm[val.first] = val.second;
  }
  for(pair<int,int> val : b.nums){
    newm[val.first] += val.second;
  }
  return newm;
}

void build(int id, int left, int right){
    if (left == right){
        segtree[id].mini = data[left];
        segtree[id].gcd = data[left];
        segtree[id].nums[data[left]] = 1;
        return;
    }

    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);

    segtree[id].mini = min(segtree[id * 2].mini, segtree[id * 2 + 1].mini);
    segtree[id].gcd = gcd(segtree[id * 2].gcd, segtree[id * 2 + 1].gcd);
    segtree[id].nums = merge(segtree[id * 2], segtree[id * 2 + 1]);
}

void update(int id, int left, int right, int uid, int val){
    if (left == right){
        segtree[id].mini = val;
        segtree[id].gcd = val;
        map<int,int> pmap;
        pmap[val] = 1;
        segtree[id].nums = pmap;
        return;
    }

    int mid = (left + right) / 2;

    if (uid <= mid){
        update(id * 2, left, mid, uid, val);
    } else {
        update(id * 2 + 1, mid + 1, right, uid, val);
    }

    segtree[id].mini = min(segtree[id * 2].mini, segtree[id * 2 + 1].mini);
    segtree[id].gcd = gcd(segtree[id * 2].gcd, segtree[id * 2 + 1].gcd);
    segtree[id].nums = merge(segtree[id * 2], segtree[id * 2 + 1]);
}

int query1(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return INF;
    if (qleft <= left && qright >= right) return segtree[id].mini;

    int mid = (left + right) / 2;
    return min(query1(id * 2, left, mid, qleft, qright),
                query1(id * 2 + 1, mid + 1, right, qleft, qright));
}

int query2(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return INF;
    if (qleft <= left && qright >= right) return segtree[id].gcd;

    int mid = (left + right) / 2;
    return gcd(query2(id * 2, left, mid, qleft, qright),
                query2(id * 2 + 1, mid + 1, right, qleft, qright));
}

int query3(int id, int left, int right, int qleft, int qright, int theNum){
    if (left > qright || right < qleft) return 0;
    if (qleft <= left && qright >= right) return segtree[id].nums[theNum];

    int mid = (left + right) / 2;
    return query3(id * 2, left, mid, qleft, qright,theNum) + query3(id * 2 + 1, mid + 1, right, qleft, qright,theNum);
}

int main(){
    cin >> N >> Q;
    for (int i = 0; i < N; i++){
      cin >> data[i];
    }
    build(1, 0, N - 1);
    for (int i = 0; i < Q; i++){
        string cmd;
        int a, b;

        cin >> cmd >> a >> b;

        if (cmd == "C"){
          update(1, 0, N - 1, a, b);
        }else if (cmd == "M"){
          cout << query1(1, 0, N - 1, a, b) << endl;
        } else if (cmd == "G"){
          cout << query2(1, 0, N - 1, a, b) << endl;
        }else{
          cout << query3(1, 0, N - 1, a, b, query2(1, 0, N - 1, a, b)) << endl;
        }
    }
}
