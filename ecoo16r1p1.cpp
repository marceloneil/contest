#include <iostream>
using namespace std;
int main(){
  int t,a,p,q,n,pass;
  for(int i = 0 ; i < 10;i++){
    cin>>t>>a>>p>>q>>n;
    pass = 0;
    for(int i = 0;i<n;i++){
      double tot = 0.0;
      double a1,a2,a3,a4;
      cin >>a1>>a2>>a3>>a4;
      tot += a1*t/100;
      tot += a2*a/100;
      tot += a3*p/100;
      tot += a4*q/100;
      if(tot >= 50.0){
        pass++;
      }
    }
    cout<<pass<<endl;
  }
}
