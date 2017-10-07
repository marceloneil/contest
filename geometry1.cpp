#include <iostream>
#include <algorithm> // sqrt

using namespace std;
int main(){
  int n;
  cin>>n;
  while(n--){
    int a,b,c,d,e,f;
    double p;
    p = 0.0;
    cin>>a>>b>>c>>d>>e>>f;
    p+=sqrt(((a-c)^2) + ((b-d)^2));
    p+=sqrt(((a-c)^2) + ((d-f)^2));
    p+=sqrt(((b-d)^2) + ((d-f)^2));
    cout<<p<<endl;
  }
}
