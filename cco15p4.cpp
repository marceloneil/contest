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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;


int n,m;
int graph[2005][2005];

int indegree[2005][2005];
vector<pair<int,int>> edges[2005][2005];
/*
queue<int> topsort(){
  queue<int> Q;
  for(int i = 1; i<=n;i++){
    if(indegree[i] == 1 ){
      Q.push(i);
    }
  }
  queue<int> finalQueue;
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    finalQueue.push(v);
    for(int nd: edges[v]){
      if( --indegree[nd] == 1 ){
        Q.push(nd);
      }
    }
  }
  return finalQueue;
}
*/



int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <=n;i++){
    string hi;
    cin>>hi;
    for(int a = 1;a <=m;a++){
      if(hi[a-1] == 'N'){
        graph[i][a] = 1;
      }else if(hi[a-1] == 'E'){
        graph[i][a] = 2;
      }else if(hi[a-1] == 'S'){
        graph[i][a] = 3;
      }else if(hi[a-1] == 'W'){
        graph[i][a] = 4;
      }
    }
    for(int i = 1; i <=m;i++){
      vector<pair<int,int>> tails;
      for(int a = 1; a <=m;a++){
        if(graph[i][a]){
          while(!tails.empty()){
            pair<int,int> aPoint = tails.back();tails.pop();
            edges[aPoint.F][aPoint.S].push_back({i,a});
            indegree[i][a]+=tails.size();
          }
        }
        if(graph[i][a] == 2){
          tails.push_back({i,a});
        }
      }
    }
  }
}
