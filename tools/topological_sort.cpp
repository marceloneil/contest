#include <bits/stdc++.h>
using namespace std;

int n;
int indegree[505];
vector<int> edges[505];
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
