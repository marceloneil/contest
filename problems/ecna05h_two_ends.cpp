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

int n;
int arr[1003];
int sum[1003];
int dp[1003][1003];
int gameCount = 0;

int greedTot, optTot;
void greedy(int l, int r);
void optimal(int a, int b){
  if(a == b){
    optTot+=arr[a];
    return;
  }//memset(dp,0,sizeof dp);
  for (int size = 0; size < b; size++){
    for (int l = a; l+size <= b; l++){
      int r = l + size;
      if (l == r) dp[l][r] = sum[r]-sum[l-1];
      else dp[l][r] = sum[r]-sum[l-1]-min(dp[l+1][r],dp[l][r-1]);
    }
  }
  if(dp[a+1][b] > dp[a][b-1]){
    optTot+=arr[b];
    greedy(a,b-1);
  }else{
    optTot+=arr[a];
    greedy(a+1,b);
  }
}

void greedy(int l, int r){
  if(l == r){
    greedTot+=arr[l];
    return;
  }
  if(arr[l] >= arr[r]){
    greedTot += arr[l];
    optimal(l+1,r);
  }else{
    greedTot += arr[r];
    optimal(l,r-1);
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n != 0){
    optTot = 0;
    greedTot = 0;
    gameCount++;
    for(int i = 1; i <=n;i++){
      cin>>arr[i];
      sum[i] = sum[i-1] + arr[i];
    }
    memset(dp, INF, sizeof dp);
    optimal(1,n);
    cout<<"In game " + to_string(gameCount)+ ", the greedy strategy might lose by as many as " + to_string(optTot - greedTot) + " points."<<endl;
    cin>>n;
  }
}
