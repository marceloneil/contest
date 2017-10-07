#include <iostream>
using namespace std;

int n,e,dist;

int x[2005], d[2005], visited[2005];
int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d",&x[i]);
    d[i] = x[i];
  }
  int loc = 0;
  int dist = x[0];
  int e = x[0];
  while( e > 0){
    for(int i = 0 ; i < n; i++){
      if(abs(d[i]-loc) <= e){

      }
    }
  }
}
/*
int runTowards(int curLoc, vector<int> arr){
  for(int i = 0 ; i < n; i++){
    int hasVisited = 0;
    for(int j = 0; j < arr.size(); j++){
      if(arr[j] == x[i]){
        hasVisited = 1;
      }
    }
    if(hasVisited == 0 && abs(x[i]-loc) <= e){
      e+= x[i];
      arr.push_back(x[i]);
      runTowards(d[i], arr);
    }
  }
}
*/
