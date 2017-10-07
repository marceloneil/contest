#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
  ll x1,y1,x2,y2;
  float m,b,f;
  scanf("%lld %lld",&x1,&y1);
  scanf("%lld %lld",&x2,&y2);

  m = -(y2-y1)/(x2-x1);
  b = -m*x1 + y1;
  f = -b/m;
  cout<<(b*f)/2<<endl;
}
