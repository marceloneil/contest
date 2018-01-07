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

vector<pair<int,int>> edges[100005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1;i<n;i++){
    int a,b;
    char c;
    cin>>a>>b>>c;
    if(c == 'r'){
      edges[a].PB({b,1});
      edges[b].PB({a,1});
    }else{
      edges[a].PB({b,0});
      edges[b].PB({a,0});
    }
  }
  
}
