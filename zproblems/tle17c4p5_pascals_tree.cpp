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

stack<ll> calculated;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  ll n,m;
  scanf("%lld %lld",&n,&m);
  if(n%2 == 0){
    printf("%d\n",1);
    for(int i = 0;i<=(n/2)-1;i++){
      if(i == 0){
        calculated.push(n);
        printf("%lld\n",n%m);
      }else{
        ll ans = calculated.top()*(n-i)/(i+1);
        calculated.push(ans);
        printf("%lld\n",ans%m);
      }
    }
    calculated.pop();
    while(!calculated.empty()){
      printf("%lld\n",calculated.top()%m);
      calculated.pop();
    }
    printf("%d",1);
  }else{
    printf("%d\n",1);
    for(int i = 0;i<=(n/2)-1;i++){
      if(i == 0){
        calculated.push(n);
        printf("%lld\n",n%m);
      }else{
        ll ans = calculated.top()*(n-i)/(i+1);
        calculated.push(ans);
        printf("%lld\n",ans%m);
      }
    }
    while(!calculated.empty()){
      printf("%lld\n",calculated.top()%m);
      calculated.pop();
    }
    printf("%d",1);
  }
}
