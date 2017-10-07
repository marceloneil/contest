#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 10000005
ll tbit[MAXN], arr[MAXN];

void add(ll* bit, ll i, ll val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

ll sum(ll* bit, ll i){
    ll sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}
//how to solve the problem. Every score added is placed in a bit. I sum up all the values of the arr up to the index of the added val
int main(){
  ll n,tot;
  scanf("%lld",&n);
  for(ll i = 1; i <= n;i++){
    scanf("%lld", &arr[i]);
    //note: if I need to retrieve the value of the bit at the nth index, I might just want tos tpore the stuff in an array
    add(tbit,arr[i],1);
    tot += sum(tbit,arr[i]);
  }
  printf("%f",((double)(tot)/(double)n));
}
