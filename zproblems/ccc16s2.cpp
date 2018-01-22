#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t, n, speedCount;
  cin>>t;
  cin>>n;
  int dmoj[n];
  int peg[n];

  for(int i =0, x; i <n; i++){
    cin >> dmoj[i];
  }
  sort(dmoj, dmoj + n);
  for(int i =0, x; i <n; i++){
    cin >> peg[i];
  }
  sort(peg, peg + n);
  //min
  speedCount = 0;
  if(t == 1){
    for(int i = 0; i < n; i++){
      speedCount += max(dmoj[i], peg[i]);
    }
  }else{
    for(int i = 0; i < n; i++){
      speedCount += max(dmoj[i], peg[n-i-1]);
    }
  }
  cout<<speedCount<<endl;
}
