//what the heck is this messed up question
#include <iostream>
using namespace std;
int main(){
  string word;
  cin>>word;
  int pass = 1;
  for(int i = 0; i < word.length; i++){
    if(word[i] != 'I' && word[i] != 'O' && word[i] != 'S' && word[i] != 'H' && word[i] != 'Z' && word[i] != 'X' && word[i] != 'N'){
    }else{
      pass = 0;
    }
  }
  if(pass){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
