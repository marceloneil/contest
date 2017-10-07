//we are using disjoint set for this
//btw william, your slides for this structure has an error. you can't have an array ca;;ed rank because it clashes with a name from the namespace
#include <iostream>
#include <cstring> //memset
#include <queue> //priority_queue
#include <vector> //vector
using namespace std;

const int maxn = 5005;
int lead[maxn];
int trank[maxn];

void make_set(int n){
  lead[n] = n;
  trank[n] = 1;
}

int find(int n){
  if (lead[n] == n) return n;
  lead[n] = find(lead[n]);
  return lead[n];
}


void merge(int a, int b){
  a = find(a);
  b = find(b);
  if (a != b){
    if (trank[a] > trank[b]) lead[b] = a;
    else{
      lead[a] = b;
      if (trank[a] == trank[b]) trank[b]++;
    }
  }
}


vector<pair<int, int> > adj[5005];
int main(){
  int n,m;
  cin>>n>>m;

  for(int i = 1 ; i <=m; i++){
    make_set(i);
  }
  //generate adj list
  for(int f,s,i,c = 0; i < m; i ++){
    cin>>f>>s>>c;
    adj[f].push_back(make_pair(s,c));
    adj[s].push_back(make_pair(f,c));
  }

}
