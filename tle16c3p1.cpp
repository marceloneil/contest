#include <iostream>
#include <set>
using namespace std;
int main(){
  int n;
  cin>>n;
  set<string> b;
  set<string> failed;
  for(int i = 0 ; i < n ; i ++){
    string word;
    cin>>word;
    if(b.count(word) != 0){
      failed.insert(word);
      b.erase(word);
    }
    if(failed.count(word)==0){
        b.insert(word);
    }
  }
  cout<<b.size()<<endl;
}
