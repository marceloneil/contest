#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
/*ll fibonacci(ll n){
  if(n == 0) return 0;
  if(n==1) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}*/
ll fibonacci(ll n){
    return round(pow((sqrt(5)+1)/2,n)-pow(-(1-sqrt(5))/2,-n))/sqrt(5);
}
/*ll fibonacci(ll n){
    (pow((sqrt(5)+1)/2,n)-pow(-(1-sqrt(5))/2,-n))/sqrt(5);
}*/
int main(){
  ll n;
  cin>>n;
  cout<<(fibonacci(n)%1000000007)<<endl;
}
