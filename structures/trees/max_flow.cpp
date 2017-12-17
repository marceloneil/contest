#include <iostream>
#include <cstring> //memset
#include <queue> //priority_queue
#include <vector> //vector
using namespace std;

int main(){
  int n,m;
  cin>>n;
  vector<pair<int, int> > adj[5005];
  for(int i = 0 ; i < n-1; i++){

  }
  cin>>m;
  for(int i,j,a = 0 ; a < m;a++){
    cin>>i>>j;
    adj[i].push_back(make_pair(j,c));
    adj[j].push_back(make_pair(i,c));
  }
}
