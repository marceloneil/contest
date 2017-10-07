#include <iostream>
using namespace std;
struct node{
  int hi = 1;
  node(int n){
    hi = n;
  }
  node(){

  }
  void yo(int n){
    hi = n;
  }
};
node* root = new node(5);
int main(){
  cout<<root->hi<<endl;
  root->yo(50);
  cout<<root->hi<<endl;
  node s(5);
  cout<<s->hi<<endl;
}

/*
scoped things:
node s(5);

*/
