#include<bits/stdc++.h>
using namespace std;

void findFactors(int num){
  for(int i = 1; i < (int) sqrt(num) + 1; i++){
    if (num % i == 0){
      if(i*i == num){
        cout<<i<<endl;
      }else{
        cout<<i<<endl;
        cout<<num/i<<endl;
      }
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout<<"enter a number"<<endl;
  int number;
  cin>>number;
  cout<<endl;
  findFactors(number);
}
