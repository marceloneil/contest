#include <bits/stdc++.h>
using namespace std;

#define MN 100005
#define F first
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

int bit[1025][1025];

int S;
//Update function for cell (x, y)
void update(int x, int y, int val){
  int y1;
  while(x <= S){
    y1 = y;
    while(y1 <= S){
      bit[x][y1] += val;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}

//Query cumulative frequency from (1, 1) to (x, y)
int query(int x, int y){
  int sum = 0;
  while(x > 0){
    int y1 = y;
    while(y1 > 0){
      sum += bit[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
  return sum;
}

//Overloaded function to query cumulative frequency from (x1, y1) to (x2, y2)
int query(int x1, int y1, int x2, int y2){
  return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int n;
int main(){
  while(true){
    int inst;
    scanf("%d",&inst);
    if(inst == 3) return 0;
    if(inst == 0){
      scanf("%d",&S);
    }
    if(inst == 1){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      update(a+1,b+1,c);
    }
    if(inst == 2){
      int a,b,c,d;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      printf("%d\n", query(a+1,b+1,c+1,d+1));
    }
  }
}
