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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)

ll psa[2003];
int dist[2003];
int energy[2003];
int dp[2003][2003];

int minl,maxr;
int n;
int calc(int l, int r, bool end){ // end = 1 = end at left side
  if(r >= n) return 0;
  if(l<0) return 0;
  if(end){
    if(dp[l][r]){
      return dp[l][r];
    }
  }else{
    if(dp[r][l]){
      return dp[r][l];
    }
  }
  if(dist[l] <=0 && dist[r] >=0){
    //cout<<dist[l]<<" "<<dist[r]<<endl;
    if(l == r){
      dp[l][r] = energy[l];
      dp[r][l] = energy[l];
      return dp[r][l];
    }
    if(end){ // I might have an infinite loop where dp[l][r] always = 0 and I can't calculate it
    int ans1 = calc(l+1,r,1) - (dist[l+1] - dist[l]); // see if fax can travel that far
    if(ans1 >= 0){
      dp[l][r] = max(dp[l][r], ans1 + energy[l]);
      minl = min(minl,l);
      maxr = max(maxr,r);
    }
    int ans2 = calc(r,l+1,0) - (dist[r] - dist[l]);
    if(ans2 >= 0){
      dp[l][r] = max(dp[l][r], ans2 + energy[l]);
      minl = min(minl,l);
      maxr = max(maxr,r);
    }
    return dp[l][r];
  }else{
    int ans1 = calc(l,r-1,1) - (dist[r] - dist[l]);
    if(ans1 >= 0){
      dp[r][l] = max(dp[r][l], ans1 + energy[r]);
      minl = min(minl,l);
      maxr = max(maxr,r);
    }
    int ans2 = calc(r-1,l,0) - (dist[r] - dist[r-1]);
    if(ans2 >= 0){
      dp[r][l] = max(dp[r][l], ans2 + energy[r]);
      minl = min(minl,l);
      maxr = max(maxr,r);
    }
    return dp[r][l];
  }
}
return 0; // fax is not in range
}

vector<PII> arr;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i = 1; i <=n;i++){
    int a,b;
    cin>>a>>b;
    arr.PB({a,b});
  }
  sort(vall(arr));
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
  //memset(dp, -1,sizeof dp);

  calc(0,n-1,1);
  ll ans1 = psa[maxr] - psa[minl-1];
  maxr = 0;
  minl = 0;
  calc(0,n-1,0);
  ll ans2 = psa[maxr] - psa[minl-1];
  cout<<max(ans1,ans2)<<endl;

// dp[x][y] represents the max amount of distance left over for fax to go to each house wthin the range
// dp[x][y] also represents that fax ends off at the xth house.

}
