//http://wcipeg.com/problem/RevDig

#include <iostream>
#include <cstring> //memset
#include <queue> //priority_queue
#include <vector> //vector
using namespace std;

int lakes[10005];
int rivers[5];
int main(){
  int n,m;
  cin>>m>>n;
  for(int f,i = 0 ; i < m+1; i++){
    cin>>f;
    lakes[i] = f;
  }
  for(int a,b,i = 0 ; i < n+2;i++){
    cin>>a>>b;
    //adj[i].push_back(make_pair(j,c));
    //adj[j].push_back(make_pair(i,c));
  }
}
