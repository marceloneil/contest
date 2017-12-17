#include <stdio.h>
#include <algorithm>
#define MAXN 1003
#define LOGN 10
using namespace std;

int lookup[LOGN][MAXN];
void build(int A[MAXN], int n) {

    int h = floor(log2(n));

    // base case
    for (int j = 0; j < n; j++) lookup[0][j] = A[j];

    // iterative dynamic programming approach
    for (int i = 1; i <= h; i++)
        for (int j = 0; j + (1<<i) <= n; j++)
            lookup[i][j] = min(lookup[i-1][j], lookup[i-1][j + (1<<(i-1))]);
}

int query(int l, int r) {// THIS IS IMPORTANT: query in range [l,r)
    int p = 31 - __builtin_clz(r-l);
    return min(lookup[p][l], lookup[p][r-(1<<p)]);
}

int arr[6] = {5,3,2,3,51,2};

int main(){
  build(arr,6);
  //query in range [l,r)
  printf("%d",query(4,6));
}
