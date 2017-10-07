#include <iostream>

using namespace std;
int main(){
  int n,e;//n = number of nodes, e = num edges
  cin>>n>>e;
  int arr[n][n];
  while(e--){
    int a,b,c; // from node a to b with cost c
    cin>>a>>b>>c;
    arr[a][b] = c;
  }
  for(int k = 0; k < n;k++){
    for(int i = 0; i < n;i++){
      for(int j =0;j<n;j++){
        arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
      }
    }
  }
}
