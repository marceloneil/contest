#include <bits/stdc++.h>
using namespace std;

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
typedef vector<PII> VPII;
#define MN 100005

ll arr[100005];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n,m;
  cin>>n>>m;
  if(m == 1){
    cout<<1<<endl; return 0;
  }
  if(m == 2){
    fill(aall(arr),0);
    cout<<arr[3]<<endl;
    for(int i = 1; i<=n;i++){
      arr[i+1] += arr[i];
      arr[i+3] += arr[i];
    }
    cout<<arr[n]<<endl;
    return 0;
  }
  arr[1] = 1;
  for(int i = 1; i<=n;i++){
    for(int a = i+1;a<=m && a <=n;a++){
      arr[a]+=arr[i];
    }
  }
  cout<<arr[m]<<endl;
}
