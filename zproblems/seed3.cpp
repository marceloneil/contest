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

int diffArr[100005];
int arr[100005];

int ans;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int i,n,j;
  cin>>i>>n>>j;
  for(int a = 1; a <=j;a++){
    int x,c,v;
    cin>>x>>c>>v;
    diffArr[x]+=v;
    diffArr[c+1]-=v;
  }
  for(int a=1;a<=j;a++){
    arr[a] = arr[a-1] + diffArr[a];
    if(arr[a] >=n){
      ans++;
    }
  }
  cout<<i-ans;
}
