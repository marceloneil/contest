#include <bits/stdc++.h>
using namespace std;

#define MAXN 28
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


//okay. idk y but this doesn't work


map<char,set<char>> graph;
vector<pair<char,char> > edges;
map<char,int> visited;

void resetVisited(){
  for(pair<char,int> hi: visited){
    visited[hi.F] = 0;
  }
}

int dfs(char a){
  if(visited[a]){
    return 0;
  }
  if(a == 'B'){
    return 1;
  }
  visited[a] = 1;
  int test = 0;

  for(char hi : graph[a]){
    test = max(test, dfs(hi));
  }
  return test;
}

int main(){
  char a,b;
  scanf("%c%c\n",&a,&b);
  while(a != '*' && b != '*'){
    graph[a].insert(b);
    graph[b].insert(a);
    edges.push_back(make_pair(a,b));
    scanf("%c%c",&a,&b);
  }

  /*
  if(dfs('A') == 0){
    printf("\nThere are 0s disconnecting roads.");
    return 0;
  }*/

  int count = 0;
  for(int i = 0 ; (unsigned)i < edges.size(); i++){
    graph[edges[i].F].erase(edges[i].S);
    graph[edges[i].S].erase(edges[i].F);
    resetVisited();
    if(dfs('A') == 0){//can't find b
      printf("%c%c", edges[i].F, edges[i].S);
      count++;
    }
    graph[edges[i].F].insert(edges[i].S);
    graph[edges[i].S].insert(edges[i].F);
  }

  printf("\nThere are %d disconnecting roads.",count);
}
//brute force this bad boy :)
//remove every edge one by one. Then check to see if you can dfs from a to b
//store each edge removed then add it into a set or smthn.
//once you're done print out the set
