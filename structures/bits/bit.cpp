#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int tbit[MAXN], arr[MAXN];

void add(int* bit, int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

int sum(int* bit, int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    } return sum;
}

int main(){
  int n,q;
  scanf("%d %d",&n,&q);
  for(int i = 1; i <= n;i++){
    scanf("%d", &arr[i]);
    //note: if I need to retrieve the value of the bit at the nth index, I might just want to store the stuff in an array
    add(tbit,i,arr[i]);
  }
  while(q--){
    string type;
    cin>>type;
    if(type == "C"){
      int idx, val;
      cin>>idx>>val;
      int diff = val - arr[idx];
      //I'm adding here so I will know the difference if a problem requires it.
      add(tbit,idx,diff);
      arr[idx] = val;

    }else if(type == "Q"){//NOTE IF THIS DOESN'T WORK IT MIGHT BE BC I'M ONE-INDEXING THE BIT
      int l, r;
      cin>>l>>r;
      int ans = sum(tbit,r)-sum(tbit,l-1); //l,r, inclusive
      scanf("%d",&ans);
    }
  }
}
