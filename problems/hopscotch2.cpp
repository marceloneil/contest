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
int arr[17000005];
int idx[17000005];
ll dp[17000005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,k;
  cin>>n>>k;
  for(int i = 1; i <=n;i++){
    cin>>arr[i];
  }
  n++;
  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  for(int i = 1; i <=n;i++){
    for(int a = 1; a <=k;a++){
      if(i-a >=0){
        if(dp[i-a] + arr[i] < dp[i]){
          dp[i] = dp[i-a] + arr[i];
          idx[i] = i-a;
        }else if(dp[i-a] + arr[i] == dp[i]){
          if(i-a > idx[i]){
            idx[i] = i-a;
          }
        }
      }
    }
  }
  cout<<dp[n]<<endl;
  int curIdx = n;
  stack<int> ans;
  while(true){
    curIdx = idx[curIdx];
    if(curIdx != 0){
      ans.push(curIdx);
    }else{
      break;
    }
  }
  while(!ans.empty()){
    cout<<ans.top()<<" ";
    ans.pop();
  }
}
