//This question is pretty ez. All I have to do is run two djiekstras. One for the minimum distance to the last node (from the tunnels)
// and one for the minimum amount of sunshine to each node
//if the minimum amount of sunshine to the last node exceeds s, then output -1. (I should calculate this djiekstra first)

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int s,n,e;
map<int, vector<int>> edges;

int max

int goToOthers(int currentPoint, vector<int> visitedPoints, int sunLeft){
  if (sunLeft < 0){
    return -1;
  }
return 0;
}


int main(){
  cin>>s;
  cin>>n>>e;
  for (int i = 0;i<e;i++){
    int u,v;
    cin>>u>>v;
    //the tunnels are bi-drectional
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}
