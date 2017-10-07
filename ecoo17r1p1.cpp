#include <iostream>
using namespace std;
int main(){
  for(int i = 0; i < 10; i++){
    double n,a,b,c,d,p,tot;
    tot = 0.0;
    cin>>n;
    cin>>a>>b>>c>>d;
    cin>>p;
    tot+= p * a * 12;
    tot+= p * b * 10;
    tot+= p * c * 7;
    tot+= p * d * 5;
    if(tot*0.5 <=n){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
}
