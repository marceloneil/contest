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

long dp[1003][1003];

int w1[1003], w2[1003];
int n1,m1;
int lcs(){
    for (int i = 1; i <= n1+1; i++){
        for (int j = 1; j <= m1+1; j++){
            if (i == 1 || j == 1)
                dp[i][j] = 0;
            else if (w1[i - 1] == w2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n1+1][m1+1];
}

//flawed
void findSubsequence(int a, int b){
  if(a == 0 || b == 0){
    return;
  }
  if(w1[a] == w2[b]){
    cout<<w1[a]<<endl;
    findSubsequence(a-1,b-1);
  }else{
      if(dp[a-1][b] == dp[a][b]){
        findSubsequence(a-1,b);
      }else if(dp[a][b-1] == dp[a][b]){
        findSubsequence(a,b-1);
      }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n1>>m1;
  for(int i = 1; i <=n1;i++){
    cin>>w1[i];
  }
  for(int i = 1; i <=m1;i++){
    cin>>w2[i];
  }
  cout << lcs() << endl;
  findSubsequence(n1+1,m1+1);
}
