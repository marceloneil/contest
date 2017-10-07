#include<iostream>
#include<map>
using namespace std;
int main(){
  std::map<std::string, std::string> b;
  b.insert(pair<string, string>("CU", "see you"));
  b.insert(pair<string, string>(":-)", "I'm happy"));
  b.insert(pair<string, string>(":-(", "I'm unhappy"));
  b.insert(pair<string, string>(";-)", "wink"));
  b.insert(pair<string, string>(":-p", "stick out my tongue"));
  b.insert(pair<string, string>("(~.~)", "sleepy"));
  b.insert(pair<string, string>("TA", "totally awesome"));
  b.insert(pair<string, string>("CCC", "Canadian Computing Competition"));
  b.insert(pair<string, string>("CUZ", "because"));
  b.insert(pair<string, string>("TY", "thank-you"));
  b.insert(pair<string, string>("YW", "you're welcome"));
  string word;
  cin>>word;
  while(word != "TTYL"){
    if(b.count(word) != 0){
      cout<<b[word]<<endl;
    }else{
      cout<<word<<endl;
    }
    cin>>word;
  }
  cout<<"talk to you later"<<endl;
}
