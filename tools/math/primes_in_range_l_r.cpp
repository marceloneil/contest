//wip
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> SieveOfEratosthenes(int n){
  bool prime[n+1];
  memset(prime, true, sizeof(prime));
  for (int p=2; p*p<=n; p++){
    if (prime[p] == true){
      for (int i=p*2; i<=n; i += p){
        prime[i] = false;
      }
    }
  }
  //print the primes
  vector<int> primes;
  for (int p=2; p<=n; p++){
    if (prime[p]){
      primes.push_back(p);
    }
  }
  return primes;
}

//my plan was to run the sieve twice and then take the differences between the two sets.
//but I realized that a quicker way was to just don't start looking for primes until we get the the l num
//we can find all primes up the r and then only record the primes that are above l. Wayy faster.
int main(){
    int n = 30;
    SieveOfEratosthenes(n);
    return 0;
}
