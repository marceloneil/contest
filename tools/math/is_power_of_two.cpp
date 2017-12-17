#include <bits/stdc++.h>
using namespace std;

//We use a mathematical concept that if we have to find wether X is a power of 2 then X ^ X-1 ( '^' Stands for XOR logic operation ) will return 0 value only when the X is a power of 2.
int ispowerof2 (int x){
  if (!x || (x&(x-1))) return 1;
  return 0;
}

int main (){
  int number;
  printf ("Enter A Number : ");
  scanf ("%d", &number);

  if (ispowerof2 (number)){
    printf ("Not a power of 2");
  }else{
    printf ("Power of 2");
  }
}
