//How to solve this problem. first you bomb the entire array. This is tricky because the bombs have an array of 50 and you really don't want to expand the 2d array
//to have that kind of buffe.r although you ave the memory if you actiuvely try to change tiels that are beyond the bomb area then you are wasting your time.
//just try to write code to limit it so it doens't go out of bounds.
//now all you have to do is run d on the graph from thestarting point to the nedinng point.
#include <iostream>
using namespace std;
int h,w,b,sx,sy,rx,ry,arr[1003][1003];
void bombPlace(int a,int b, int c, int d){
  if(a == 1){
    for(int i = 0 ; i < d;i++){
      for(int w = 0; w < d;w++){
        if(i + w - d )
      }
    }
  }else if(a == 2){

  }else{

  }
}

int main(){
  scanf("%d %d %d\n%d %d %d %d",&h,&w,&b,&sx,&sy,&rx,&ry);
  for(int i = 0 ; i < b;i++){
    int bt,bx,by,br;
    scanf("%d %d %d %d",&bt,&bx,&by,&br);
    bombPlace(bt,bx,by,br);
  }
}
