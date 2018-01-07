#include <bits/stdc++.h>
#define ll long long
using namespace std;


int ans(int a,int b){
  return a^b;
}

int main(){
  int arr[] = {12, 12, 14, 90, 14, 14, 14};
  int theAns = 0;
  for(int i =0;(unsigned)i< sizeof arr;i++){
    theAns = ans(theAns,arr[i]);
  }
  cout<<theAns<<endl;
  cout<<(5^1)<<endl;
}
