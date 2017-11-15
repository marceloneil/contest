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

map<string,<vector<string>>> rip;
stack<string> counts;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,l;
  cin>>l>>n;
  while(l--){
    string lastName = "";
    for(int i = 1; i<=n;i++){
      string hi;
      cin>>hi;
      if(!counts.empty()){
          rip[hi].push_back(counts.top());
          counts.push_back(hi);
      }
    }
  }
}
