//backwards priority queue and then see if the distance with the foods cna reach it

#include <iostream>
#include <map>
using namespace std;
int f,b,arr[100000003],energy,count;
map<string,int> foods;
int main(){
  energy = 0;
  count = 0;
  cin>>f;
  while(f--){
    string temp;
    int temp1;
    cin>>temp>>temp1;
    foods[temp] = temp1;
  }
  cin>>b;
  while(b--){
    string temp1;
    int temp2;
    cin>>temp1>>temp2;
    arr[temp2] += foods[temp1];
  }
  for(int i = 0; i < 1000000003; i++){
    energy += arr[i];
    if(arr[i] != 0){
      count++;
    }
    if(energy < 0){
      cout<<count<<endl;
      return 0;
    }
    energy --;
  }
}
