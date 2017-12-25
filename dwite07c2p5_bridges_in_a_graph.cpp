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

VI edges[105];
bool vis[105];
int b1, b2;

int connectedCount = 0;
void checkConnected(int cur){
  vis[cur] = 1;
  for(int i : edges[cur]){
    if(!vis[i]){
      if((i == b1 && cur == b2) || (i == b2 && cur == b1)){
      }else{
        checkConnected(i);
        connectedCount++;
      }
    }
  }
}

int main(){
  int n,m,ans;
  scanf("%d %d",&n,&m);
  for(int i = 0; i <m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i =0;i<=n;i++){
      for(int e : edges[i]){
        connectedCount = 0;
        memset(vis, 0,sizeof vis);
        b1 = e;
        b2 = i;
        checkConnected(i);
        if(connectedCount != n-1){
          ans++;
        }
      }
  }
  printf("%d", ans);

}
