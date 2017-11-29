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

int ans[1000003],arr[1000003];
int main(){
  /*cin.sync_with_stdio(0);
  cin.tie(0);*/
  int n;
  scanf("%d", &n);
  for(int i = 1; i<=n;i++){
    scanf("%d", &arr[i]);
    if(arr[i-1] > arr[i]){
      ans[i] = 1;
      printf("%d ", 1);
    }else{
      if(i == 1){
        printf("%d ", 0);
        continue;
      }
      ans[i] = ans[i-1] + 1;
      printf("%d ", ans[i]);
    }
  }
}
