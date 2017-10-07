#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int[2]> bad;
int main(){
  int xh,yh, t;
  cin>>xh>>yh;
  cin>>t;
  for(int i = 0 ; i < t; i++){
    int x,y,l;
    cin>>x>>y>>l;
    for(int a = x-l; a < x + l+1; a++){
      for(int b = y - l; b < y+l+1; b++){
         bad.insert(a,b);
      }
    }
  }

}
