#include <bits/stdc++.h>
using namespace std;

#define MN 100005
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

int dist[100005],val[100005],dp[100005];
//int calc(int )

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int x,d,n,p;
  cin>>x;
  if(x == 1){
    cin>>d>>n>>p;
    for(int i = 1; i<=p;i++){
      int q,r;
      cin>>q>>r;
      dist[i] = q;
      val[i] = r;
    }
    val[0] = n;
    dp[0] = 1;
    p +=1;
    dist[p] = d;
    for(int i = 0; i <p;i++){
      for(int a = i+1; a <=p;a++){
        if(dist[a] - dist[i] <= val[i]){
          dp[a]+=dp[i];
        }else{
          break;
        }
      }
    }
    cout<<dp[p]%MOD<<endl;
  }else{
    int w;
    cin>>w;

  }
}
