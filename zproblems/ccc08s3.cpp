//the logic seems legit but the input is flawed

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

char graph[24][24];
int timet[24][24];
int visited[24][24];

int r,c;

void bfs(){
  memset(visited,0,sizeof visited);
  queue<pair<pair<int, int> ,int> >q;
  q.push(make_pair(make_pair(1,1),0));

  visited[1][1] = 1;
  while (!q.empty()){
    pair< pair<int,int>,int> cur = q.front(); q.pop();
    if(cur.F.F == r && cur.F.S == c){
      cur.S++;
      printf("%d", cur.S);
      break;
    }
    cur.S ++;
    if(cur.S < timet[cur.F.F][cur.F.S]){
      timet[cur.F.F][cur.F.S] = cur.S;
    }
    if(graph[cur.F.F][cur.F.S] == '+'){
      if(visited[cur.F.F-1][cur.F.S] == 0){
          visited[cur.F.F-1][cur.F.S] = 1;
          q.push(make_pair(make_pair(cur.F.F-1, cur.F.S),cur.S));
      }
      if(visited[cur.F.F][cur.F.S-1] == 0){
          visited[cur.F.F][cur.F.S-1] = 1;
          q.push(make_pair(make_pair(cur.F.F, cur.F.S-1),cur.S));
      }
      if(visited[cur.F.F+1][cur.F.S] == 0){
          visited[cur.F.F+1][cur.F.S] = 1;
          q.push(make_pair(make_pair(cur.F.F+1, cur.F.S),cur.S));
      }
      if(visited[cur.F.F][cur.F.S+1] == 0){
          visited[cur.F.F][cur.F.S+1] = 1;
          q.push(make_pair(make_pair(cur.F.F, cur.F.S+1),cur.S));
      }
    }else if(graph[cur.F.F][cur.F.S] == '-'){
      if(visited[cur.F.F][cur.F.S-1] == 0){
          visited[cur.F.F][cur.F.S-1] = 1;
          q.push(make_pair(make_pair(cur.F.F, cur.F.S-1),cur.S));
      }
      if(visited[cur.F.F][cur.F.S+1] == 0){
          visited[cur.F.F][cur.F.S+1] = 1;
          q.push(make_pair(make_pair(cur.F.F, cur.F.S+1),cur.S));
      }
    }else if(graph[cur.F.F][cur.F.S] == '-'){
      if(visited[cur.F.F-1][cur.F.S] == 0){
          visited[cur.F.F-1][cur.F.S] = 1;
          q.push(make_pair(make_pair(cur.F.F-1, cur.F.S),cur.S));
      }
      if(visited[cur.F.F+1][cur.F.S] == 0){
          visited[cur.F.F+1][cur.F.S] = 1;
          q.push(make_pair(make_pair(cur.F.F+1, cur.F.S),cur.S));
      }
    }
  }
}

int main(){
  scanf("%d", &r);
  scanf("%d", &c);
  for(int i = 1; i <= r; i++){
    for(int a = 1 ; a <= c; a++){
      scanf("%c",&graph[i][a]);
    }
  }
  bfs();
}
