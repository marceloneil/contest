#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i = 0 ;i < n;i++){
    int num;
    cin>>num;
    if(num == 0){
      cout<<"0000"<<endl;
      continue;
    }
    string binary = "";
    while(num != 0){
      binary = to_string(num%2) + binary;
      num = num/2;
    }
    string newString = "";
    while(binary.size()%4 != 0){
      binary = "0" + binary;
    }
    for(int a = 0 ;(unsigned)a < binary.size(); a++){
      if(a%4 == 0 && a != 0){
        newString = newString + " ";
      }
      newString = newString + binary[a];
    }
    cout<<newString<<endl;
  }
}
