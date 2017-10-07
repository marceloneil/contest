#include <iostream>
#include <map>
using namespace std;
map<string, int> dict;
int main(){
  //remember to add the cin>>n to loop the test cases
  string sentence;
  cin>>sentence;
  while(sentence != "\n"){
    string words[4];//split the input property and you're set
    string currSentence = "";
    for(int i =0;(unsigned)i<sizeof(words);i++){
      if(currSentence != ""){
        currSentence = currSentence + " ";
      }
      if(dict.count(words[i])){
        currSentence = currSentence + words[i];
        dict[words[i]] = dict[words[i]] + 1;
      }else{
        dict[words[i]] = 1;
      }
    }
    cin>>sentence;
  }
}
