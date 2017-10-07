#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,m;
  //int skyscrapers[30005];
  vector<pair<int, int> > doge[5005];
  //vector< vector< pair<int,int> > > doge[30005];
  cin>>n>>m;
  for(int i = 0 ; i < m;i++){
    int b,p;
    cin>>b>>p;
    int start = b%p;
    for(int a = start; a < n; a+=p){
      pair<int,int> doge1 = make_pair(1,a+p);
      pair<int,int> doge2 = make_pair(1,a-p);
      doge[a].push_back(doge1);
      doge[a].push_back(doge2);
    }
  }
  for(int b = 0 ; b < 5005; b++){
    for(int i = 0 ; i < doge[b].size(); i++){
      //wait this is weird
      doge[b].push_back(make_pair(doge[b][i])
    }
  }
  //I should first run a dfs on the graph to check id doge a is connected to doge b

  // now I have to run djikstra on doge to find the min distance.
}
