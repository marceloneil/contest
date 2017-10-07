//this is a wip. help me willy
#include <iostream>
#include<vector>
#include <cstddef>
using namespace std;

struct Node{
  struct Node *lc;
  struct Node *rc;
  int value;
  Node(int val){
    value = val;
  }
};
vector<Node> bst;
int find(int val){
  int nodeIndex = 0;
  while(bst[nodeIndex].value != 0){
    if(bst[nodeIndex].value == val){
      return nodeIndex;
    }
    if(val > bst[nodeIndex].value){
      nodeIndex = nodeIndex*2 + 2;
    }else{
      nodeIndex = nodeIndex*2 + 1;
    }
  }
  return -1;
}
/*
void insert(int val){
  int nodeIndex = 0;
  Node newNode = new Node(val);
  while(bst[nodeIndex].value != 0){
    if(bst[nodeIndex].value == val){
      //set the Node to
      nodeIndex = nodeIndex*2 + 2;
      bst.add(nodeIndex*2 + 2, new struct)
    }
    if(val > bst[nodeIndex].value){
      nodeIndex & nodeIndex*2 + 2;
    }else{
      nodeIndex = nodeIndex*2 + 1;
    }
  }
}*/

int largest(){
  if (bst.size() > 0){
    int largest = bst[0].value;
    for(int i = 0; i <(int)bst.size(); i+=2 ){
      if(bst[i].value > largest){
        largest = bst[i].value;
      }
    }
    return largest;
  }
  return -1;
}
