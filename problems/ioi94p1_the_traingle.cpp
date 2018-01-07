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

int arr[101][101]; int sums[101][101];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    for(int a = 1;a<=i;a++){
      cin>>arr[i][a];
    }
  }
  for(int i = n; i >=1;i--){
    for(int a = i;a>=1;a--){
      sums[i][a] = arr[i][a] + max(sums[i+1][a],sums[i+1][a+1]);
    }
  }
  cout<<sums[1][1]<<endl;
}
