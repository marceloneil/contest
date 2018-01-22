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
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;


int edit_distance(const std::string & s1, const std::string & s2) {
  int n = s1.size(), m = s2.size();
  std::vector< std::vector<int> > dp;
  dp.resize(n + 1, std::vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int j = 0; j <= m; j++) dp[0][j] = j;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = dp[i][j];
      } else {
        dp[i + 1][j + 1] = 1 + std::min(dp[i][j],
          //replace
          std::min(dp[i + 1][j],
            //insert
            dp[i][j + 1])); //delete
          }
        }
      }
      return dp[n][m];
    }
    int main() {
      string orig;
      int n;
      float minCount = INF;
      cin>>orig;
      cin>>n;
      for(int i = 0; i < n;i++){
        int t;
        cin>>t;
        float count = 0;
        for(int a = 0; a < t;a++){
          string temp;
          cin>>temp;
          count+= edit_distance(orig, temp);
        }
        if(count/t < minCount){
          minCount = count/t;
        }
      }
      cout<<minCount<<endl;
      //cout<<round(minCount*100)/100<<endl;
    }
