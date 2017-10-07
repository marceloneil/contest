#include <iostream>
#include <map>
#include <vector>
#include <cstring> //memset
using namespace std;
int timeWhenMet[30];

map<int, vector<int>> edges;
bool checkOthers(int originalVertex, int currentVertex, int timeLeft){
  if(timeLeft == 1){
    for(int i = 0 ; (unsigned)i < edges.size(); i++){
      if(edges[currentVertex][i] == originalVertex)return true;
    }
    return false;
  }
  if(timeLeft == 2){

  }

  return true;
}



int main(){
  memset(timeWhenMet, -1,sizeof(timeWhenMet));
  int n;
  cin>>n;
  for(int i = 0 ; i < n;i++){
    int u,v;
    cin>>u>>v;
    edges[u].push_back(v);
  }
  for(int i = 0 ; (unsigned)i < edges.size(); i++){
    for (int a = 0 ; (unsigned)i < edges[i].size(); a++){//asks all vertexes to checkOthers
      checkOthers(i,a,3);
    }
  }
}
