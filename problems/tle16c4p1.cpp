#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
  ll n, weight, count;
  cin>>n;
  ll arr[n];
  for(ll i = 0; i < n;i++){
    cin>>arr[i];
  }
  sort(arr, arr+n);
  weight = arr[0];
  count = 1;
  for(ll i = 1 ; i < n ; i++){
    if(arr[i] >= weight){
      count++;
      weight+= arr[i];
    }
  }
  cout<<count<<endl;
}
