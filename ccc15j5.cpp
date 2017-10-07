#include <iostream>
using namespace std;
int dp[255][255];
int main(){
  int n,k;
  cin>>n>>k;
  //#people #pies #ways
  //2       2     1
  //2       3     1
  //2       4     2
  //2       5     2
  //2       6     3
  //3       3     1
  //3       4     1
  //3       5     2
  //3       6     3


  //
  //     -            or       -
  //   - -      -   -      -   -
  // - - -  = - - + -    - - + -
  //keep track of then umber of pies used for the previous pattern and the number of pies required for this pattern

//dp[x][y] = number of ways that pie can be given out based on the x, the number of people and y, the number of pies.

  for(int x =0 ;x<k;x++){
    for(int y = 0;y<k;y++){
      int minLayers = y/x;
      dp[x][y] = max()
    }
  }
}
