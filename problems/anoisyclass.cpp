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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

set<int> deadEnd;
vector<int> graph[10005];

bool dfs(int node){
  if(deadEnd.count(node) != 0){
    return false;
  }
  if(graph[node].size() == 0){
    deadEnd.insert(node);
    return false;
  }
  for(int hi : graph[node]){
    if(dfs(hi)){
      return true;
    }
  }return false;
}

int main(){
  int n,q;
  scanf("%d", &n);
  scanf("%d", &q);
  for(int i = 0 ; i < q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    graph[a].push_back(b);
  }
  for(int i = 0;i<n;i++){
    int visited[10005];
    memset(visited, 0, sizeof visited);
    if(dfs(i)){
      printf("%s","No");
    }
  }
}
