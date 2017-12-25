// Compute the greatest common divisor for x and y
// Divide both of them by the GCD

#include <bits/stdc++.h>
using namespace std;
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

pair<int,int> reduceFraction(int numerator, int denominator){
  int temp = gcd(numerator, denominator);
  return {(numerator/temp),(denominator/temp)};
}
int main(){
  int a = 5;
  int b = 10;
  pair<int,int> temp = reduceFraction(a,b);
  cout<<temp.first<<" "<<temp.second<<endl;
}
