#include <iostream>
using namespace std;
string word;
string newWord = "";
void round(int idx){
  if(word.at(idx) < 110){
    newWord = "a" + newWord;
  }else{
    newWord = "z" + newWord;
    if(idx != 0){
      if(word.at(idx-1) == 'z'){
        round(idx-1);
      }else{
        word.at(idx-1) = word.at(idx-1)+1;
      }
    }else{
      newWord = "a" + newWord;
    }
  }
}
int main(){
  cin>>word;
  for(int i = word.length() -1; i >=0 ;i++){
    round(i);
  }
  cout<<newWord<<endl;
}
