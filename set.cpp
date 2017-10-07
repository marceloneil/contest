#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  cin>>n;
  std::set<int> b;
  for(int i = 0 ; i < n ; i++){
    int a;
    cin>> a;
    b.insert(a);
  }
  cout<<b.size()<<endl;
}
