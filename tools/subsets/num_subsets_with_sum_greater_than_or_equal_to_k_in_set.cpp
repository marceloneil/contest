#include <bits/stdc++.h>
using namespace std;

int solve(int set[1003], int set_size, int val){
  int count = 0;
  for(int x = 0; x < pow(2,set_size); x++){ // not sure if it's < or <=
  int sum = 0;
  for(int k = 0; k < set_size;k++){// not sure if it's < or <=
  if(kth bit is set in x){
    sum = sum + set[k];
  }
}
if( sum >= val){
  count = count + 1;
}
}
return count
}
