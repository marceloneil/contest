//not submitted
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n, w, previous, mint, maxt, bot, top;
  mint = 0;
  maxt = 0;
  cin>>n>>w;
  int arr[n];
  for(int i = 0 ; i < n; i++){
    cin>>arr[i];
  }
  sort(arr, arr + n);
  previous = w;
  //max
  bot = 0;
  top = n-1;
  for(int i = 0; i < n; i++){
    if(abs(bot-w) > abs(top-previous)){
      if(abs(bot-w) > abs(top-w)){
        maxt += abs(bot-w);
        previous = abs(bot-w);
        bot++;
      }else{
        maxt += abs(top-w);
        previous = abs(top-w);
        top--;
      }
    }else if(abs(top-w) > abs(top-previous)){
      if(abs(top-w) > abs(bot-w)){
        maxt += abs(top-w);
        previous = abs(top-w);
        top--;
      }else{
        maxt += abs(bot-w);
        previous = abs(bot-w);
        bot++;
      }
    }
  }
  previous = w;
  //min
  for(int i = 0 ; i < n; i++){
    if(abs(arr[i]-w) > abs(arr[i]-previous)){
      mint += abs(arr[i]-previous);
    }else{
      mint += abs(arr[i]-w);
    }
    previous = arr[i];
  }
  cout<<mint + " " + maxt <<endl;
}
