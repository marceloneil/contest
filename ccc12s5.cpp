//this code is wrong. look at william's lecture slides for the right version. I think I loop over the same cells too many times (no visited array)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r,c,k;
int arr[27][27];
int look(int x,int y){
  int val = 0;
  if(x-1 == 0){
    val = 1;
  }
  if(y-1 == 0){
    val = 1;
  }
  if(x == 0 && y == 0){
    val = 0;
  }
  if(arr[x-1][y] != 99999999){
    val+=arr[x-1][y];
  }
  if(arr[x][y-1] != 99999999){
    val+=arr[x][y-1];
  }
  arr[x][y] = val;
  //cout<<y<<endl;
  if(x == r && y ==c){
    cout<<val<<endl;
  }else{
    if(x+1 != r+1){
      look(x+1,y);
    }
    if(y+1 != c+1){
      look(x,y+1);
    }
  }
}

int main(){
  cin>>r>>c;
  cin>>k;
  for(int i = 0 ; i < k;i++){
    int temp1,temp2;
    cin>>temp1>>temp2;
    arr[temp1][temp2] = 99999999;
  }
  look(1,1);
  /*for(int i = 0 ; i < r; i++){
  for(int j = 0 ; j < c; j++){
  arr[i][j] = 1;
}
}*/
}
