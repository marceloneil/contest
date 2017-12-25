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

VI capList[102];
ll dp[1025][101];

int allMask;
ll countWaysUtil(int mask, int i){
  if(mask == allMask) return 1;
  if(i>100)return 0;
  if(dp[mask][i] != -1) return dp[mask][i];
  ll ways = countWaysUtil(mask, i+1);
  int size = capList[i].size();
  for (int j = 0; j < size; j++){
    if (mask & (1 << capList[i][j])) continue;
    ways += countWaysUtil(mask | (1 << capList[i][j]), i+1);
    ways %=MOD;
  }
  return ways;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,x;
  cin>>n;
  allMask = (1 << n) - 1;
  string temp, str;
  getline(cin, str);  // to get rid of newline character
  for (int i=0; i<n; i++){
    getline(cin, str);
    stringstream ss(str);
    while (ss >> temp){
      stringstream s;
      s << temp;
      s >> x;
      // add the ith person in the list of cap if with id x
      capList[x].push_back(i);
    }
  }
  memset(dp, -1, sizeof dp);
  cout<<countWaysUtil(0,1)<<endl;


}
