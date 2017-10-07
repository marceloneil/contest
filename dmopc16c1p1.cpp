//https://dmoj.ca/problem/dmopc16c1p1
#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int count = 0;
for(int i = 0 ; i < n ; i ++){
  int a;
  cin>>a;
  if(a %2 ==  i%2){
    count++;
  }
}
cout<<count<<endl;
}
