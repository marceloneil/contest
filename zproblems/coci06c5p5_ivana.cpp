#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
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

int dp[MAXN][MAXN], arr[MAXN];

//every range has a left and right side. (what will happen if she chooses the left side or the right side, who will win?)

//0 = left side
//1 = right side

/*  
bool findWays(int l1, int r1, int l2,int r2){ // (....]....[....)
  if(r1 + 2 == l2){
    return dp[l][r] = arr[l]; // if the range is 1 number then it is either 1 or 0
  }
  if()
  int ans = max(arr[l] + findWays(l-1,r),arr[r]+findWays(l,r+1));

}*/

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1 ; i <= n;i++){
    int temp;
    scanf("%d",&temp);
    arr[i] = temp%2;
  }
}
