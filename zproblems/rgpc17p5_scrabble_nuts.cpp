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

string X,Y;
int dp[][];
//get input
for (int i = 0; i <= X.length(); i++){
  for (int j = 0; j <= Y.length(); j++){
    if (i == 0) dp[i][j] = j;
    else if (j == 0) dp[i][j] = i;
    else if (X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1];
    else{
      dp[i][j] = min( dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
      }
    }
  }
  print dp[X.length()][Y.length()]


int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n,m;
  cin>>n>>m;
  string a,b;
  cin>>a>>b;

}
