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
int n,x,y;

struct aclass{
  VI p;
  aclass(VI pp){
    p = pp;
  };
};

void dfs(int last){

}
vector<aclass> allClass;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>x>>y;
  for(int i = 1;i<=n;i++){
    int p,s;
    cin>>p>>s;
    VI pp;
    for(int a = 1; a<=s;a++){
      int temp;
      cin>>temp;
      pp.PB(temp);
    }
    allClass.PB(pp);
  }
}
