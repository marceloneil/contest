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
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

//I definitely need a 2d prefix sum array because I am finding the sun of rectangles
int n,m,arr[55][55],prefixSum[55][55];

int findVal(int x1,int y1, int x2, int y2){
  return prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i = 1 ; i <= n;i++){
    for(int a = 1; a <= m;a++){
      scanf("%d", &arr[i][a]);
    }
  }
  for(int i = 1; i <= n;i++){
    for(int a = 1; a <= m;a++){
      prefixSum[i][a] = prefixSum[i-1][a] + prefixSum[i][a-1] - prefixSum[i-1][a-1] + arr[i][a];
    }
  }
  
}
