#include <iostream>
using namespace std;
#define ll long long
ll factor(ll n){
  return n/5 + n/25 + n/125 + n/625 + n/3125 + n/15625 + n/78125 + n/390625 + n/1953125 + n/9765625 + n/48828125 + n/244140625 + n/1220703125 + n/6103515625 + n/30517578125;
}
ll N = 700000000000;
int main(){
  ll a,b,c,d,mid;
  cin>>a>>b;
  ll lo = 1, hi = N, target = a;
  while(lo < hi){
    mid = (lo + hi)/2;
    if (factor(mid) >= target){
      hi = mid;
    }
    else{
      lo = mid+1;
    }
  }
  c = lo;
  lo = 1;
  hi = N;
  target = b;
  while(lo < hi){
    mid = (lo + hi)/2;
    if (factor(mid) > target){
      hi = mid;
    }
    else{
      lo = mid+1;
    }
  }
  d = lo;
  cout<<d-c<<endl;
}
