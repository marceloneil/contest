//not submitted
#include <iostream>
using namespace std;
#define ll long long
int main(){

  ll curf, planetc, n, s;
  planetc = 1;
  cin>>n>>s;
  ll a[n];
  ll b[n];
  for(ll i = 0; i < n ; i++){
    cin>>a[i]>>b[i];
  }
  curf = a[s-1];
  for(ll i = 0 ; i < n; i++){
    if(i != s-1){
      if(a[i] >= b[i]){
        planetc++;
        curf += (a[i]-b[i]);
      }
    }
  }
  cout<<curf<<endl;
  cout<<planetc<<endl;
}
