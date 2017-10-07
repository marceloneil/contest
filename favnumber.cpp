#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>
using namespace std;
#define max 100000

int main(){
  int n ,q;
  cin>>n;
  int nums[n];
  for (int i = 0 ; i < n;i++){
    cin>>nums[i];
  }
  sort(nums,nums + n);
  cin>>q;
  for(int i = 0 ; i < q;i++){
    int lo, hi, target;
    cin>>target;
    lo = 0;
    hi = n-1;
    while(lo < hi){
      int mid = (lo + hi)/2;
      if (mid >= target){
        hi = mid;
      }else{
        lo = mid+1;
      }
    }
    cout<<lo<<endl;
    }
  }
