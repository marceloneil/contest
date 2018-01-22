#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
vector<pair<int,int> > nodes[200003];
int graphs[200003], graphs2[200003];;
int cost[200003];
void bfs1(int num,int ttime){
  if(graphs[num] > ttime){
    graphs[num] = ttime;
  }
  vector<pair<int,int> > nodesInQueue;
  for(int i = 0; (unsigned)i < nodes[num].size();i++){
    nodesInQueue.push_back(nodes[num][i]);
  }
  while(!nodesInQueue.empty()){
    bfs1(nodesInQueue.back().first,ttime + nodesInQueue.back().second);
    nodesInQueue.pop_back();
  }
}

void bfs2(int num,int ttime){
  if(graphs2[num] > ttime){
    graphs2[num] = ttime;
  }
  if(graphs2[num] > graphs[num]){ // stop doing bfs because the other wind eara already reched it
    return;
  }
  vector<pair<int,int> > nodesInQueue;
  for(int i = 0; (unsigned)i < nodes[num].size();i++){
    nodesInQueue.push_back(nodes[num][i]);
  }
  while(!nodesInQueue.empty()){
    bfs2(nodesInQueue.back().first,ttime + nodesInQueue.back().second);
    nodesInQueue.pop_back();
  }
}

int main(){
int n,m,x,y,q;
cin>>n>>m>>x>>y;
  for(int i = 0; i < m;i++){
    int a,b,c;
    cin>>a>>b>>c;
  }
  memset(graphs, INF, sizeof graphs);
  bfs1(x,0);
  bfs2(y,0);
  cin>>q;
  while(q--){

  }
}
