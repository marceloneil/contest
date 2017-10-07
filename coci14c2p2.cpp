#include <iostream>
#include <map>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<string, int> people;
  for(int i = 0; i < n;i++){
    string name;
    cin>>name;
    people[name] = people[name]+1;
  }
  for(int i = 0; i < n-1;i++){
    string name;
    cin>>name;
    people[name] = people[name]-1;
  }
  for(pair<string,int> name : people){
    if(name.second == 1){
      cout<<name.first<<endl;
    }
  }
}
