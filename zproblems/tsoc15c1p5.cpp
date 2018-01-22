#include <iostream>
#include <vector>
using namespace std;
vector<int> nodes[103];
vector<int> nodesToBeRemoved;
int dispensers[103];
int distances[103];

void dfs(int loc, int dist){
  if(dist + 1 >= distances[loc])return;
  distances[loc] = dist + 1;
  for(int i = 0;(unsigned)i < nodes[loc].size(); i++){
    dfs(loc, dist);
  }
}

int main(){
  int n,m,w;
  cin>>n>>m;
  for(int i = 0 ; i < m;i++){
    int x,y;
    cin>>x>>y;
    nodes[x].push_back(y);
    nodes[y].push_back(x);
  }
  cin>>w;
  for(int i =0; i < w;i++){
    int temp;
    cin>>temp;
    nodesToBeRemoved.push_back(temp);
  }

  //I need to make a catch in case w is zero
  int globalShortest = 0;
  bool canReach = true;
  while(canReach){
    for(int i = 0; (unsigned)i < nodesToBeRemoved.size(); i++){
      for(int a = 0; (unsigned)a < nodes[i].size(); a++){
        nodesToBeRemoved.push_back(nodes[i][a]);
      }
    }
    for(int num : nodesToBeRemoved){
        nodes[num].empty();
    }

    nodesToBeRemoved.empty();
    int shortest = 0;//dfs code to check if a path exists
    if(shortest != -1){
      if(shortest < globalShortest){
        globalShortest = shortest;
      }
    }else{
      canReach = false;
    }
  }
  cout<<globalShortest<<endl;
}
