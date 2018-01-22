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
#define MAXN 205

int N,M,numGirls;
VI edges[MAXN];
bool cuteGirls[MAXN],vis[MAXN];
int match[MAXN];
// I have to use ford fukerson and max flow to solve this problem

bool bpm(int cur){
  for(int i : edges[cur]){
    if(!vis[i]){
      vis[i] = 1;
      if(!match[i] || bpm(match[i])){ // if this girl is free or if I can move someone to antoher girl
        match[i] = cur;
        return 1;
      }
    }
  }
  return 0;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  for(int i = 0;i<N;i++){
    int t;
    cin>>t;
    for(int a =0;a<t;a++){
      int temp;
      cin>>temp;
      if(i == 0){
        cuteGirls[N + temp - 1] = 1;
        numGirls++;
      }else if(cuteGirls[N + temp - 1]){
        edges[i].PB(N + temp - 1);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <N + M;i++){
    memset(vis, 0, sizeof vis);
    if(bpm(i)) ans++;
  }
  cout<<numGirls - ans<<endl;
}
