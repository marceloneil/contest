#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

long long indegree[10004];
vector<int> slides[10004];
int visited[10004];
int sumOfWays[10004];
int a,b;
int count = 0;
void dfs(int node, int combinations){
  sumOfWays[node]+=combinations;
  if(--indegree[node] == 0){
    visited[node] = 1;
    for(int nd: slides[node]){
      if(!visited[nd])
      dfs(nd,sumOfWays[node]);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i = 1; i <=m;i++){
    cin>>a>>b;
    slides[a].push_back(b);
    indegree[b]+=1;
  }
  indegree[1] = 1;
  dfs(1,1);
  if(sumOfWays[2] < 1000000000){
    cout<<sumOfWays[2];
    return 0;
  }
  string ans = to_string(sumOfWays[2]%1000000000);
  int numZeros = 10-(ans.size());
  for(int i = 1;i<numZeros;i++){
    ans = "0"+ans;
  }
  cout<<ans<<endl;
}
