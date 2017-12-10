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

int wait[100005],moves[100005];
int n,m;
map<PII,int> memo;
int calc(int cur, int idx){
  if(idx >= n) return 0;
  if(memo.count({cur,idx}) != 0){
    //cout<<"hi"<<endl;
    return memo[{cur,idx}];
  }
  int ans = 0;
  for(int i = 1; i <= m;i++){
    if(i == cur){
      ans = max(ans,calc(i,idx+1));
    }else{
      ans = max(ans,calc(i,idx+wait[i]));
    }
  }
  if(moves[idx] == cur){
    ans++;
  }
  return memo[{cur,idx}] = ans;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <=n;i++){
    cin>>moves[i];
  }
  for(int i = 1; i <=m;i++){
    cin>>wait[i];
  }
  cout<<calc(1,1)<<endl;
  for(pair<PII,int> e : memo){
    cout<<e.F.S<<" "<<e.F.S<<endl;
  }
}
