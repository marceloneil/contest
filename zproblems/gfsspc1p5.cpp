//HOLY CRAP I CAN'T BELIEVE I THOUGHT OF THE RIGHT ANSWERRRR. I still need to finish it tho
#include <iostream>
#include <algorithm>
#include <cmath> //abs
using namespace std;

int longest = 999999;
int main(){
  int n,t;
  cin>>n>>t;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  sort(arr, arr + n);
  t = t-1;
  for(int i = 0; i + t < n; i++){
    int distNeeded;
    if(arr[i+t] <= 0){//negative range
      if(arr[i+t+1] <0){
        continue;
      }
      distNeeded = -arr[i];
    }else if(arr[i] >= 0 ){//positive range
      if(arr[i-1] >0){
        continue;
      }
      distNeeded = arr[i + t];
    }else{
      int smaller = min(arr[i],arr[i+t]);
      int larger = max(arr[i],arr[i+t]);
      distNeeded = 2*abs(smaller) + abs(larger);
    }
    if(distNeeded < longest){
      longest = distNeeded;
    }
  }
  cout<<longest<<endl;
}
