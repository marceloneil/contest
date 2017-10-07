#include <iostream>
#include <map>
using namespace std;

#define ll long long

int main(){
  int n, m, q;
  scanf("%d %d %d",&n,&m,&q);
  int arr[n];
  map<ll,ll> hi;

  for(int i = 0 ; i < n; i++){
    int tVal;
    scanf("%d",&tVal);
    arr[i] = tVal;
    hi[tVal] = i;
  }
  for(int i = 0 ; i < q; i++){
    int va,vb;
    scanf("%d %d",&va,&vb);
    ll val = 0;
    for(int j = hi[va]; j <= hi[vb]; j++){
      val+= arr[j];
    }
    if(val/2 >= m){
      printf("Enough\n");
    }else{
      printf("Not enough\n");
    }
  }
}
