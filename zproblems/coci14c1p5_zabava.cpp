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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

int arr[105][503];
int dp[105][503];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int dorms[105];
  int n,m,k;
  cin>>n>>m>>k;
  for(int i = 1; i<=n;i++){
    int temp;
    cin>>temp;
    dorms[temp]++;
  }

  for(int i = 1; i <=m;i++){
    for(int a = 1;a<=k;a++){ // a = the number of times we clean the dorm
      int n1 = dorms[i]/(a+1); // number of days for each cleanout
      int completeSections = (a+1)*n1*(n1+1)/2;
      int residualParties = (n1+1)*(dorms[i]%(a+1));
      arr[i][a] = completeSections + residualParties;
    }
  }
  memset(dp, INF, sizeof dp);
  for(int i = 0;i<=m;i++){
    dp[0][i] = 0;
  }
  for(int i = 1; i<=m;i++){ // for each dorm
    dp[i][0] = dorms[i]*(dorms[i] + 1)/2;
    for(int a = 1;a<=k;a++){
      for(int s = 0; s <=a;s++){ // s represents the number of a the current dorm uses
        dp[i][a] = min(dp[i-1][a-s] + arr[i][s],dp[i][a]);
      }
    }
  }
  cout<<dp[m][k]<<endl;
}
