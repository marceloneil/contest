#include <stdio.h>
#define INF 0x3f3f3f3f
int gcd(int a, int b){
  if (a == INF){
    return b;
  }else if(b == INF){
    return a;
  }else if (a == 0 || b == 0){
    return 0;
  }else if (a == b){
    return a;
  }else if (a > b){
    return gcd(a-b, b);
  }
  return gcd(a, b-a);
}

// Driver program to test above function
int main(){
  int a = INF, b = 56;
  printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
}
