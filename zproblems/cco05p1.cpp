#include <iostream>
#include <cstring>
#include <string> // to_string
using namespace std;
int arr[105][105];
int visited[105][105];
int n,m,i,j,p;
bool dfs(int row,int col){
  if(!visited[row][col] && (arr[row][col] == i || arr[row][col] == j || arr[row][col] == p)){
    visited[row][col] = 1;
    if( row == m){
      return true;
    }
    return (dfs(row-1,col) || dfs(row,col-1) || dfs(row+1,col) || dfs(row,col+1));
  }else{
    return false;
  }
  return false;
}
int main(){
  memset(arr,-1,sizeof arr);
  cin>>n>>m;
  for(int a = 1;a<=m;a++){
    for(int b = 1; b <= n;b++){
      cin>>arr[a][b];
    }
  }
  for(i = 0; i < 10;i++){
    for(j = 0; j <10;j++){
      for(p = 0; p < 10;p++){
        for(int x = 1; x <= n;x++){
          memset(visited, 0, sizeof(visited[0][0]) * 105 * 105);
          if(dfs(1,x)){
            int small = min(i,min(j,p));
            int large = max(i,max(j,p));
            if(i < large && i > small){
              cout<<to_string(small) + " " + to_string(i) + " " + to_string(large)<<endl;
            }else if(j < large && j > small){
              cout<<to_string(small) + " " + to_string(j) + " " + to_string(large)<<endl;
            }else{
              cout<<to_string(small) + " " + to_string(p) + " " + to_string(large)<<endl;
            }
            return 0;
          }
        }
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
}
