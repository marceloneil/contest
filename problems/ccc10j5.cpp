//to solve this problem., just do a bfs on the graph and wait until you land onto the spot
#include <iostream>
#include <cstring>
using namespace std;
int arr[12][12];
int a,b,c,d;

void bfs(int col,int row, int count){
  if(count < arr[col][row]){
    bfs(col+2,row,count+1);
    bfs(col+2,row,count-1);
    bfs(col-2,row,count+1);
    bfs(col-2,row,count-1);

    bfs(col+1,row,count+2);
    bfs(col+1,row,count-2);
    bfs(col-1,row,count+2);
    bfs(col-1,row,count-2);
  }
}
int main(){
  memset(arr, 0x3f3f3f3f, sizeof(arr[0][0]) * 12 * 12);
  for(int i = 0 ; i < 12;i++){
    arr[0][i] = -1;
    arr[1][i] = -1;
    arr[10][i] = -1;
    arr[11][i] = -1;

    arr[i][0] = -1;
    arr[i][1] = -1;
    arr[i][10] = -1;
    arr[i][11] = -1;
  }
  cin>>a>>b>>c>>d;
  bfs(a+2,b+2,0);
  cout<<arr[c+2][d+2]<<endl;
}
