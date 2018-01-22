  //https://dmoj.ca/problem/dmopc16c1p2
#include <iostream>
using namespace std;
struct segType {
  int val1, val2, lazy, good;
};
int main(){
  int n;
  cin >>n;
  int m [n];
  int b [n];
  for(int i = 0 ; i < n;i++){
    cin >>m[i]>>b[i];
    cout<<m[i]<<endl;
  }
  for(int i = 0; i < n;i++){
    for(int a = 0; a < n; a++){
      if(i != a && m[a] == m[i] && b[a] == b[i]){
        cout<<"Infinity"<<endl;
          break;
      }
    }
  }
}
