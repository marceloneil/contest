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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int main(){
  int n;
  int arr[2006];
  int dp[1006];
  int sum[1006];
  scanf("%d",&n);
  for(int i = 1 ; i <= n*2;i++){
    scanf("%d",&arr[i]);
    sum[i] = sum[i-1] + arr[i];
  }
  for(int i = 1 ; i <= n*2;i++){
    for(int a = 1; a <=10;a++){
      if(i-a >= 0){
        if((i-a)%2 == 0){
          dp[i] = max(dp[i],dp[i-a] -1  + sum[i] - sum[i-a]);
        }else{
          dp[i] = max(dp[i], dp[i-a] -1 + sum[i] - sum[i-a + 1]); // increasing by one bc it's the next card
        }
      }
    }
  }
  cout<<dp[(n*2)]<<endl;
}
