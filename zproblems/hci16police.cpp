#include <iostream>
#include <cstring>
using namespace std;

int calcCost(int a, int b){
  return (a-b)^2;
}

int main(){
  int h,n;
  int pos[300];
  int cost[300];
  int wherePoliceHasToGo[300];
  cin>>n>>h;
  memset(cost,h,sizeof(cost));
  for(int i = 0;i<n;i++){
    cin>>pos[i];
  }

  for(int i = 1 ; i < n;i++){
    //is placing the police at i cheaper or is moving a police from i-1 or i+1 cheaper
    cost[i] = min(cost[i],calcCost(pos[i],pos[i-1]));//I'll fix the "0" later
    cost[i] = min(cost[i],calcCost(pos[i],pos[i+1]));
  }


  cout<<pos[1];
}
