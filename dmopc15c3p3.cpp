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
//literally bfs on each node and see how many go back to it.If there is one that takes 6 lengths to go back to it then yes it is good
int visited[23];
vector<int> graph[23];
int dfs(int a){
  if(visited[a]){
    return 1;
  }
  visited[a] = 1;
  int theMax = 0;
  for(int i = 0; (unsigned)i < graph[a].size(); i++){
    int count = dfs(graph[a][i]);
    if(count > theMax){
      theMax = count;
    }
  }
  if(theMax == 0){
    return -1;
  }
    theMax++;
    return theMax;
}
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0; i < m; i++){
    int a,b;

    scanf("%d %d",&a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  if(dfs(1) > 5){
    printf("%s","YES");
  }else{
    printf("%s","NO");
  }

}
