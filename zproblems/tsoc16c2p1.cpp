#include <iostream>
using namespace std;
int main(){
  int num;
  cin>>num;
  string stuff;
  cin>>stuff;
  string foo = "";
  int numX = 0;
  for(int i = 0 ; i < stuff.length(); i++){
    if(stuff[i] != 'X'){
      if(numX > 0){
        foo[foo.length() -numX] = stuff[i];
        numX = 0;
      }else{
        foo = foo + stuff[i];
      }
    }else{
      numX++;
    }
  }
  for(int i = 0 ; i < num;i++){
    string name;
    cin>>name;
    if(foo[i] == 'A'){
      cout<<"Dear "+name+", beloved artist, I would love to have you at my party. Come to my crib on April 20th."<<endl;
    }else if(foo[i] == 'O'){
      cout<<"Dear "+name+", beloved occasion enthusiast, come to my crib to celebrate this very special day."<<endl;
    }else{
      cout<<"Dear "+name+", April 20th is happening again this year. Don't miss out."<<endl;
    }
  }
}
