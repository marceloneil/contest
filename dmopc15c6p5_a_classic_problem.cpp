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

int n,arr[1000005],k;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;
  for(int i = 1; i <=n;i++){
    cin>>arr[i];
  }
  ll ans = 0;
  for(int i = 1; i <n;i++){
    int lastMin = arr[i];
    int lastMax = arr[i];
    for(int a = i + 1; a <=n;a++){
      if(arr[a] < lastMin){
        if(lastMax - arr[a] > k){
          break;
        }else{
          lastMin = arr[a];
          ans++;
        }
      }else if(arr[a] > lastMax){
        if(arr[a] - lastMin > k){
          break;
        }else{
          lastMax = arr[a];
          ans++;
        }
      }else{
          ans++;
      }
    }
  }
  ans +=n;
  cout<<ans<<endl;
}
