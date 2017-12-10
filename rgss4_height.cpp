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

int n,arr[1005], dp[1005];
/*int k = 0; //current LIS length
int ans = 0;


int lower_bound(int lo,int hi,int target){
lo = 0, hi = n;
while(lo < hi){
int mid = (lo + hi)/2;
if (mid >= target){
hi = mid;
}else{
lo = mid+1;
}
}
return lo;
}


void lis(){
for (int i = 1; i <= n; i++){
int pos = lower_bound(dp,dp+k,arr[i]) - dp;
dp[pos] = arr[i];
if (pos == k) k++;
}
cout<<k<<endl;
}*/


//input and DP here
vector<int> calc_lis(){
  int len = 0;
  int tmp = len, cur = INF;
  vector<int> lis;
  for (int i = n; i > 0; i--){
    if (dp[i] == tmp && arr[i] < cur){
      lis.push_back(arr[i]);
      tmp--;
      cur = arr[i];
    }
  }
  return lis;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i =1;i<=n;i++){
    cin>>arr[i];
  }
  vector<int> temp = calc_lis();
  for(int hi : temp){
    cout<<hi<<endl;
  }
}
