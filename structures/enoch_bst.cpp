//this is a wip. help me willy
#include <iostream>
#include <vector>
#include <cstddef>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;

struct node{
  struct node *lc;
  struct node *rc;
  int value;
};

struct bst{
	struct node *root;
};

//use this to create a node
struct node * create_node(int val){
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->lc = NULL;
	n->rc = NULL;
	n->value = val;
	return n;
}

//use this to create a bst
struct bst *create_bst(){
	struct bst *b = (struct bst*)malloc(sizeof(struct bst));
	b->root = NULL;
	return b;
}

void destroy_nodes(struct node *n){
	if(n->lc)destroy_nodes(n->lc);
	if(n->rc)destroy_nodes(n->rc);
	free(n);
}

void destroy_bst(struct bst* b){
	if(b->root)destroy_nodes(b->root);
	free(b);
}
bool find_node(struct node *n, int val){
	if(!n)return 0;
	if(n->value < val)return find_node(n->rc, val);
	if(n->value > val)return find_node(n->lc, val);
	else return 1;
}

bool find(struct bst * tree, int val){
  return find_node(tree->root, val);
}

void insert_node(struct node *n, int val){
	if(n->value < val){
		if(n->lc)insert_node(n->lc, val);
		else{
			n->lc = create_node(val);
		}
	}else if(n->value > val){
		if(n->rc)insert_node(n->rc, val);
		else n->rc = create_node(val);
	}
}

void insert(struct bst *tree, int val){
	if(tree->root)insert_node(tree->root, val);
	else tree->root = create_node(val);
}

int largest_node(struct node *n){
	if(n){
		if(n->rc)return largest_node(n->rc);
		else return n->value;
	}
	return -1;
}
int largest(struct bst *tree){
	return largest_node(tree->root);
}

int main(){
	struct bst *tree = create_bst();
	insert(tree, 1);
	insert(tree, 10);
	destroy_bst(tree);//IF YOU FORGET TO DESTROY THE BST YOU WILL GET A MEMORY LEAK
}
