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

ll psa[1000005];
int main(){
  int n,q;
  scanf("%d", &n);
  for(int i = 1; i <=n;i++){
    int temp;
    scanf("%d", &temp);
    psa[i] = psa[i-1] + temp;
  }
  scanf("%d", &q);
  while(q--){
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", psa[b+1]-psa[a]);
  }
}
