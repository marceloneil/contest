//what the heck. I don't know why this doesn't work
#include <iostream>
using namespace std;
#define ll long long
int main(){
  ll high = 2000000000;
  ll low = 1;
  string input = "";
  cout<<(high+low)/2;
  cin>>input;
  while(input != "OK"){
    if(input == "FLOATS"){
      //search lower
      high = low + (high-low)/2;
      cout<<(high+low)/2;
    }else{
      //search higher
      low = low + (high-low)/2;
      cout<<(high+low)/2;
    }
    cin>>input;
  }
}
