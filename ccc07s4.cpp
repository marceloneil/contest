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


vector<int> slides[10004];
int a,b;
int count = 0;
int dfs(int x, int y){
  if()
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  cin>>a>>b;
  while(a != 0 && b != 0){
    slides[a].push_back(b);
    cin>>a>>b;
  }

}
