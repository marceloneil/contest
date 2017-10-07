
#include <bits/stdc++.h>

#define MAXN 100001
#define INF 0x3f3f3f3f

using namespace std;

int N, Q;
int segtre1[4 * MAXN], segtre2[4 * MAXN], segtre3[4 * MAXN], data[MAXN];

int gcd(int a, int b){
  if (a == 0 || b == 0){
    return 0;
  }
  if (a == b){
    return a;
  }
  if (a > b){
    return gcd(a-b, b);
  }
  return gcd(a, b-a);
}

void build1(int id, int left, int right){
    if (left == right){
        segtre1[id] = data[left];
        return;
    }

    int mid = (left + right) / 2;
    build1(id * 2, left, mid);
    build1(id * 2 + 1, mid + 1, right);

    segtre1[id] = min(segtre1[id * 2], segtre1[id * 2 + 1]);
}

void update1(int id, int left, int right, int uid, int val){
    if (left == right){
        segtre1[id] = val;
        return;
    }

    int mid = (left + right) / 2;

    if (uid <= mid){
        update1(id * 2, left, mid, uid, val);
    } else {
        update1(id * 2 + 1, mid + 1, right, uid, val);
    }

    segtre1[id] = min(segtre1[id * 2], segtre1[id * 2 + 1]);
}

int query1(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return INF;
    if (qleft <= left && qright >= right) return segtre1[id];

    int mid = (left + right) / 2;
    return min(query1(id * 2, left, mid, qleft, qright),
                query1(id * 2 + 1, mid + 1, right, qleft, qright));
}

void build2(int id, int left, int right){
    if (left == right){
        segtre2[id] = data[left];
        return;
    }

    int mid = (left + right) / 2;
    build2(id * 2, left, mid);
    build2(id * 2 + 1, mid + 1, right);

    segtre2[id] = gcd(segtre2[id * 2], segtre2[id * 2 + 1]);
}

void update2(int id, int left, int right, int uid, int val){
    if (left == right){
        segtre2[id] = val;
        return;
    }

    int mid = (left + right) / 2;

    if (uid <= mid){
        update2(id * 2, left, mid, uid, val);
    } else {
        update2(id * 2 + 1, mid + 1, right, uid, val);
    }

    segtre2[id] = gcd(segtre2[id * 2], segtre2[id * 2 + 1]);
}

int query2(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return INF;
    if (qleft <= left && qright >= right) return segtre2[id];

    int mid = (left + right) / 2;
    return gcd(query2(id * 2, left, mid, qleft, qright),
                query2(id * 2 + 1, mid + 1, right, qleft, qright));
}


void build3(int id, int left, int right){
    if (left == right){
        segtre3[id] = data[left];
        return;
    }

    int mid = (left + right) / 2;
    build3(id * 2, left, mid);
    build3(id * 2 + 1, mid + 1, right);

    segtre3[id] = min(segtre3[id * 2], segtre3[id * 2 + 1]);
}

void update3(int id, int left, int right, int uid, int val){
    if (left == right){
        segtre3[id] = val;
        return;
    }

    int mid = (left + right) / 2;

    if (uid <= mid){
        update3(id * 2, left, mid, uid, val);
    } else {
        update3(id * 2 + 1, mid + 1, right, uid, val);
    }

    segtre3[id] = min(segtre3[id * 2], segtre3[id * 2 + 1]);
}

int query3(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return INF;
    if (qleft <= left && qright >= right) return segtre3[id];

    int mid = (left + right) / 2;
    return min(query3(id * 2, left, mid, qleft, qright),
                query3(id * 2 + 1, mid + 1, right, qleft, qright));
}


int main(){
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> data[i];

    build1(1, 0, N - 1);
    build2(1, 0, N - 1);
    build3(1, 0, N - 1);

    for (int i = 0; i < Q; i++){
        string cmd;
        int a, b;

        cin >> cmd >> a >> b;

        if (cmd == "C"){
          update1(1, 0, N - 1, a, b);
          update2(1, 0, N - 1, a, b);
          update3(1, 0, N - 1, a, b);
        }else if (cmd == "M"){
          cout << query1(1, 0, N - 1, a, b) << endl;
        } else if (cmd == "G"){
          cout << query2(1, 0, N - 1, a, b) << endl;
        }else{

        }
    }
}
