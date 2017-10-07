#include <stdio.h>
int gcd(int a, int b){
  if (a == b){
    return a;
  }
  if (a > b){
    return gcd(a-b, b);
  }
  return gcd(a, b-a);
}
int lcm(int a, int b){
  return (a*b)/gcd(a, b);
}

// Driver program to test above function
int main(){
  int a = 15, b = 20;
  printf("LCM of %d and %d is %d ", a, b, lcm(a, b));
  return 0;
}
