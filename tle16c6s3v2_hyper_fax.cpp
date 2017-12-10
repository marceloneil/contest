#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int psa[2003];
int dist[2003];
int energy[2003];
int dp[2003][2003];

/*
if(end){
  dp[l][r] = max(dp[l][r], dp[l+1][r] + energy[l] - (dist[l+1] - dist[l]));
  dp[l][r] = max(dp[l][r], dp[r][l+1] + energy[l] - (dist[r] - dist[l]));
}else{
  dp[r][l] = max(dp[r][l], dp[l][r-1] + energy[r] - (dist[r] - dist[l]));
  dp[r][l] = max(dp[r][l], dp[r-1][l] + energy[r] - (dist[r] - dist[r-1]));
}*/

int calc(int l, int r, bool end){ // end = 1 = end at left side
  if(end){
    if(dp[l][r] != -1){
      return dp[l][r];
    }
  }else{
    if(dp[r][l] != -1){
      return dp[r][l];
    }
  }
  if(dist[l] <=0 && dist[r] >=0){
    if(l == r){
      dp[l][r] = energy[l];
      dp[r][l] = energy[l];
      return energy[l];
    }
    if(end){
      cout<<"hi"<<endl;
      dp[l][r] = max(dp[l][r], calc(l+1,r,1) + energy[l] - (dist[l+1] - dist[l]));
      dp[l][r] = max(dp[l][r], calc(r,l+1,0) + energy[l] - (dist[r] - dist[l]));
    }else{
      dp[r][l] = max(dp[r][l], calc(l,r-1,1) + energy[r] - (dist[r] - dist[l]));
      dp[r][l] = max(dp[r][l], calc(r-1,l,0) + energy[r] - (dist[r] - dist[r-1]));
    }
  }
  return -1; // fax is not in range
}

vector<PII> arr;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    int a,b;
    cin>>a>>b;
    arr.PB({a,b});
  }
  sort(begin(arr),end(arr));
  for(int i = 0; i < n; i++){
    if(i > 0){
      psa[i] = psa[i-1] + arr[i].S;
      dist[i] = arr[i].F;
      energy[i] = arr[i].S;
    }else{
      psa[i] = arr[i].S;
      dist[i] = arr[i].F;
      energy[i] = arr[i].S;
    }
  }
  memset(dp, -1,sizeof dp);
  cout<<calc(0,n,1)<<endl;
  cout<<calc(0,n,0)<<endl;
  // dp[x][y] represents the max amount of distance left over for fax to go to each house wthin the range
  // dp[x][y] also represents that fax ends off at the xth house.
  

}
