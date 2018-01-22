#include <iostream>
#include <set>
using namespace std;
int visited[4];
int tree[4][4];

int dfs(int a,int b){
  if(visited[a]){
    return 1;
  }
  visited[a] = 1;
  int count = 0;
  for(int i = 0 ; i < 4;i++){
    if(tree[a][i] && i != b){
      if(dfs(i,a)>count){
        count = 1;
      }
    }
  }
  return count;
}

int main(){
  int edgeCount = 0;
  for(int i = 0 ; i < 4; i++){
    for(int a = 0 ; a < 4; a++){
      scanf("%d",&tree[i][a]);
      if(tree[i][a]){
        edgeCount++;
      }
    }
  }
  if(edgeCount != 6){
    printf("%s","No");
    return 0;
  }
  int count = 0;
  for(int i = 0; i < 4;i++){
    count = dfs(i,5);
    if(count){
      break;
    }
  }
  if(count){
    printf("%s", "No");
  }else{
    printf("%s", "Yes");
  }
}
