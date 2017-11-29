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

ll num[200005];
ll prefixSum[200005];
int diff[200005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,m,k;
  cin>>n>>m>>k;
  for(int i = 1 ; i <=m;i++){
    int a,b;
    cin>>a>>b;
    diff[a]-=1;
    diff[b+1]+=1;
  }
  num[0] = m;
  for(int i = 1; i <=n;i++){
    num[i] = num[i-1] + diff[i];
    prefixSum[i] = prefixSum[i-1] + num[i];
  }
  for(int i = 1; i <=n;i++){
    for(int a = 1;a+i-1<=n;a++){
      if(prefixSum[a+i-1] - prefixSum[a-1] >= k){
        cout<<i<<endl;
        return 0;
      }
    }
  }
cout<<-1<<endl;
}
