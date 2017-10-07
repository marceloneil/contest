#include <iostream>
#define INF 2147483647
using namespace std;

struct node{
  int val = 0;
  int l;
  int r;
  node(int value){
    val = value;
  }
  node(){

  }
};


node tree[5000];
int arr[1000];

void push_up(int idx){

  //example of a push_up function for min queries
  tree[idx].val = min(tree[2*idx].val,tree[2*idx+1].val);

}
void build (int l, int r, int idx){

  tree[tree[idx].l].val = l, tree[tree[idx].r].val = r;
  if (l == r){ //this node is a leaf node
    tree[idx].val = arr[l];
    return;
  }
  int mid = (l+r)/2; //find the midpoint
  build(l,mid,2*idx); //left side
  build(mid+1,r,2*idx+1); //right side
  push_up(idx); //update answer to current node

}


int query(int queryL, int queryR, int idx){

  if (tree[idx].l >= queryL && tree[idx].r <= queryR){
    //interval is completely within query range
    return tree[idx].val;
  }
  if (tree[idx].l > queryR || tree[idx].r < queryL){
    //interval is completely out of query range
    return INF; //return some answer that will not affect //final answer
  }
  int ansL = query(queryL,queryR,2*idx);
  int ansR = query(queryL,queryR,2*idx+1);
  return min(ansL,ansR); //choose the better answer

}

void update(int idxToUpdate, int newVal, int idx){

  if (tree[idx].l == tree[idx].r){
    //whatever needs to be updated
    tree[idx].val = newVal;
    return;
  }
  int mid = (tree[idx].l + tree[idx].r)/2; //find midpoint
  if (idxToUpdate <= mid){ //update left child
    update(idxToUpdate,newVal,2*idx);
  }
  else{ //update right child
    update(idxToUpdate,newVal,2*idx+1);
  }
  push_up(idx); //update answer to current node
}


int main(){
  cout<<"hi"<<endl;
}
