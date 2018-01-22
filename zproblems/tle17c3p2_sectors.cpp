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

map<int,int> rooms;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int s,k;
  cin>>s>>k;
  for(int i = 1; i <=s;i++){
    int temp;
    cin>>temp;
    rooms[temp] = i;
  }
  ll ans = 1;
  int lastIdx = -1;
  for(int i = 1; i <=k;i++){
    int temp;
    cin>>temp;
    if(i == 1){
      lastIdx = rooms[temp];
      continue;
    }
    ans+=abs(lastIdx - rooms[temp]);
    lastIdx = rooms[temp];
  }
  cout<<ans<<endl;
}
