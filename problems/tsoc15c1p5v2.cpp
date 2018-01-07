#include <bits/stdc++.h>
using namespace std;

#define MAXN 103
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
vector<int> graph[MAXN];
int n,m,w,dispense[MAXN],timet[MAXN],visited[MAXN];
/*int dfs(int a,int count){
if(visited[a]){
return -1;
}
count+=4;
visited[a] = 1;
for(int i = 0; (unsigned)i < graph[a].size();i++){
if(timet[graph[a][i]] > count){
timet[graph[a][i]] = count;
dfs(a,count);
}
}
}*/

//there is the case where the dispenser is blocking the path but the player has walked passed it before it can dispense anything

void bfs(int start){
  memset(visited,0,sizeof visited);
  queue<pair<int,int> >q;
  q.push(make_pair(start,0));

  visited[start] = 1;
  while (!q.empty()){
    pair<int,int> cur = q.front(); q.pop();
    cur.second +=4;
    if(cur.second < timet[cur.first]){
      timet[cur.first] = cur.second;
    }
    for (int i = 0; (unsigned)i < graph[cur.first].size();i++){
      if (visited[graph[cur.first][i]] == 0){
        visited[graph[cur.first][i]] = 1;
        q.push(make_pair(graph[cur.first][i],cur.second));
      }
    }
  }
}
void bfs2(int start){
  memset(visited,0,sizeof visited);
  queue<pair<int,int> >q;
  q.push(make_pair(start,0));

  visited[start] = 1;
  while (!q.empty()){
    pair<int,int> cur = q.front(); q.pop();
    cur.second ++;
    if(cur.second < timet[cur.first]){
      if(cur.first == n){
        printf("%d", cur.second);
        return;
      }
      for (int i = 0; (unsigned)i < graph[cur.first].size();i++){
        if (visited[graph[cur.first][i]] == 0){
          visited[graph[cur.first][i]] = 1;
          q.push(make_pair(graph[cur.first][i],cur.second));
        }
      }
    }
  }
  printf("%s", "sacrifice bobhob314");
}
int main(){
  scanf("%d %d", &n,&m);
  for(int i = 0 ; i < m;i++){
    int a,b;
    scanf("%d %d", &a,&b);
    graph[a].push_back(b);
  }
  scanf("%d",&w);
  for(int i = 0; i < w;i++){
    scanf("%d",&dispense[i]);
  }
  for(int i = 0 ; i < w;i++){
    bfs(dispense[i]);
  }
  bfs2(0);
}
