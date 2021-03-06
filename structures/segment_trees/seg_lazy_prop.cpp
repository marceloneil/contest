/**
* In this code we have a very large array called arr, and very large set of operations
* Operation #1: Increment the elements within range [i, j] with value val
* Operation #2: Get max element within range [i, j]
* Build tree: build(1, 0, n-1)
* Update tree: update(1, 0, n-1, i, j, value)
* Query tree: query(1, 0, n-1, i, j)
* Actual space required by the tree = 2*2^ceil(log_2(n)) - 1
*/

#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h>

#define n 20
#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff

int arr[n];
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

int main() {
  for(int i = 0; i < n; i++) arr[i] = 1;
  build(1, 0, n-1);
  memset(lazy, 0, sizeof lazy);

  addr(0,6,4);
  addr(7,10,12);
  addr(10,n-1,100);

  cout << maxr(0, n-1) << endl; // Get max element in range [0, n-1]
}
