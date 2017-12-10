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

int n,m;
long long arr[100005], sum[100005], freq[100005];

void add(ll * bit, int i, int val){
    while(i <= 100005){
        bit[i] += val;
        i += (-i & i);
    }
}

ll fsum(ll* bit, int i){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  scanf("%d %d", &n, &m);
  for(int i = 1; i <=n;i++){
    scanf("%lld",&arr[i]);
    add(sum,i,arr[i]);
    add(freq,arr[i],1);
  }
  while(m--){
    char typeOfq;
    scanf("%s",&typeOfq);
    if(typeOfq == 'C'){
      int a,b;
      scanf("%d %d",&a,&b);
      add(sum,a,b-arr[a]);
      add(freq,arr[a],-1);
      add(freq,b,1);
      arr[a] = b;
    }
    else if(typeOfq == 'S'){
      int a,b;
      scanf("%d %d", &a,&b);
      printf("%lld\n", fsum(sum,b) - fsum(sum,a-1));
    }
    if(typeOfq == 'Q'){
      int a;
      scanf("%d", &a);
      printf("%lld\n",fsum(freq,a));
    }
  }
}
