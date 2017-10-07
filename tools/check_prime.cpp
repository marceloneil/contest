//note to self: if you need to check a lot of primes, it is better to use "primes_under_n" and then store that into an array
//that way you have O(1) lookup.
#include <iostream>
#include <cstring>
using namespace std;
const int lim = 100;
int isPrime[lim];
int main(){
  memset(isPrime,1,sizeof(isPrime));
  //memset(isPrime,*isPrime+lim,1); //set values to true
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i < lim; i++){
    if (isPrime[i]){
      for (int j = i*i; j < lim; j++){
        isPrime[j] = 0;
      }
    }
  }
  cout<<isPrime[6]<<endl;
}
