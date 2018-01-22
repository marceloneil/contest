#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
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
#define MN 100005

int arr[3005];
int dp[3005][2][105][105];
VI items;
int n,m;

// interesting address management:
// int& ret=dp[pos][take][l][r];

// THIS FUNCTION IS TERRIBLY WRONG. I NEED TO FIX IT
int calc(int idx, int prevTook, int l, int r){
  int& ret=dp[idx][prevTook][l][r];
  if(ret != -1) return ret;
  if(idx >= n){
    if(l>=r) return ret;
    if(prevTook){
      return ret = calc(idx, 0,l+1,r);
    }else{
      return ret = items[r] + calc(idx, 1,l,r-1);
    }
  }else{
    if(prevTook){
      ret = max(calc(idx + 1, 0, l,r), arr[idx] + calc(idx + 1, 1, l+1,r));
    }else{
      ret = calc(idx + 1, 1, l,r);
      if(l <= r){
        ret = max(ret, calc(idx + 1, 1, l,r));
      }
    }
  }
  return ret;
}



int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  memset(dp, -1,sizeof dp);
  cin>>n;
  for(int i = 1; i<=n;i++){
    cin>>arr[i];
  }
  cin>>m;
  for(int i = 1 ; i<=m;i++){
    int temp;
    cin>>temp;
    items.PB(temp);
  }

  //sorting cuts the complexity by m because instead of checking
  //all extra pies to insert, we only have to check in 2 spots.

  sort(vall(items)); // ascending order
}
