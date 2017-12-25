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

map<string,int> names;
string arr[12];

int dp[12][1005][1005]; // type, cost, volume

int v[12],c1[12],c2[12];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,r,s;
  cin>>n>>r>>s;
  for(int i = 1;i<=n;i++){
    string e;
    cin>>e>>v[i]>>c1[i]>>c2[i];
    names[e] = i;
    arr[i] = e;
  }
  for(int i = 1; i <=n;i++){
    for(int a = 1; a <= r;a++){
      for(int b = 1; b <= s;b++){
        dp[i][a][b] = max()
      }
    }
  }
}
