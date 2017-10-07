#include <iostream>
#include <math.h>
using namespace std;
int main(){
  long long r,c,k,s,b;
  cin>>r>>c>>k;
  b = min(r,c);
  s = ceil(sqrt(k));
  if(s * (s-1) >= k){
    if(s-1 > b){
      cout<<(long long)(b*2 + ceil((double)k/b)*2);
    }else{
      cout<<(s*2)+ (s-1)*2;
    }
  }else{
    if(s > b){
      cout<<(long long)(b*2 + ceil((double)k/b)*2);
    }else{
      cout<<(s*4);
    }
  }
}
