//this is a lot of DFS. DFS to check if you can reach the exit. DFS to see if the person can reach that spot.

//everytime the box shifts directions, I dfs to see if the person can reach that spot to move thee box in a nother dir.
//if I can't, remove the square where the box was and dfs again. Do this until  you ifnd the optimal path.

#include <iostream>
using namespace std;
int grid[35][35];
int r,c;

int dfs(int x,int y){
  if(x == 0 || y == 0 || x  == r || y == c){
    return 0;
  }
  return 1 +
}

int main(){
  cin>>r>>c;
  for(int i = 0 ; i < r;i ++){
    for(int a = 0 ; a < c; a++){
      cin>>grid[i][a];
    }
  }


}
