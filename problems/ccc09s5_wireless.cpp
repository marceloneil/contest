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

int tmax = 0;
int ccount = 0;
int arr[10005][30005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int m,n,k;
  cin>>m>>n>>k;
  while(k--){
    int x,y,r,b;
    cin>>x>>y>>r>>b;
    arr[x][y] += b;
    for(int i = x-r; i <=x+r;i++){
      if(i < 1 || i > n){
        continue;
      }
      for(int a = y-r;a<=y+r;a++){
        if(a < 1 || a > m){
          continue;
        }
        cout<<i<<" "<<a<<endl;
        int t1 = abs(x-i);
        int t2 = abs(y-a);
        if(t1*t1 + t2*t2 <= r*r){
          arr[i][a] +=b;
          if(arr[i][a] > tmax){
            tmax = 1;
            ccount = 1;
          }else if(arr[i][a] == tmax){
            ccount++;
          }
        }
      }
    }
  }
  cout<<tmax<<endl;
  cout<<ccount;
}
