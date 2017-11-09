#include <bits/stdc++.h>
using namespace std;

#define MAXN 405
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

/*

int n,arr[MAXN],dp[MAXN][MAXN][2],dp[MAXN][MAXN],isOneBall[MAXN][MAXN];
//dp[][][0] = left side of range
//dp[]][][1] = right side of range
int calc(int l, int r, int s){
  if(l == r){
    return arr[l];
  }
  if(dp[l][r][s] != -1){
    return dp[l][r][s];
  }
  theMaxVal
  for(int i = l; l+i < r;i++ ){

  }
*/
int arr[MAXN], combinable[MAXN][MAXN];
int canCombine(int l, int r){
  if(combinable[l][r] != -1){
    return combinable[l][r];
  }
  if(l == r) return 1;
  if(l-r == 1){
    if(arr[l] == arr[r]){
      combinable[l][r] = 1;
      return 1;
    }
    return 0;
  }
  if(l-r == 2){
    if(arr[l] == arr[r]){
      combinable[l][r] = 1;
      return 1;
    }
    if(canCombine(l,l+1) && 2*arr[l] == arr[r]){
      combinable[l][r] = 1;
      return 1;
    }
    if(canCombine(l+1,r) && 2*arr[r] == arr[l]){
      combinable[l][r] = 1;
      return 1;
    }
    combinable[l][r] = 0;
    return 0;
  }
  for(int i = l; i < r;i++){
    if(canCombine(l,i) && canCombine(i,r)){
      combinable[l][r] = 1;
      return 1;
    }
  }
  combinable[l][r] = 0;
  return 0;
}
int main(){
  memset(combinable,-1,sizeof combinable);
}
