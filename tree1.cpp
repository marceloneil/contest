// /https://dmoj.ca/problem/tree1
//don't know why but this is broken :/
#include <iostream>
#include <set>
using namespace std;
int visited[4];
int tree[4][4];
void visit(int curNode){
  if(visited[curNode] == 0){
    visited[curNode] = 1;
    for(int a = 0 ; a < 4; a++){
        if(tree[curNode][a] == 1){
            visit(a);
        }
    }
  }
}
int main(){
  set<int> nodes;
  for(int i = 0 ; i < 4; i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    tree[i][0] = a;
    tree[i][1] = b;
    tree[i][2] = c;
    tree[i][3] = d;
  }
  for(int i = 0; i < 4;i++){
    for(int a = 0; a < 4;a++){
      if(tree[i][a] == 1){
        nodes.insert(i);
        nodes.insert(a);
      }
    }
  }
  /*for(int element: nodes) {
    cout<<element<<endl;
  }*/
  if(nodes.size() > 0){
    visit(*nodes.begin());
  }
  if(nodes.size() == 0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
