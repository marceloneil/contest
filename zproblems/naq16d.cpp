#include <iostream>
#include <vector>
using namespace std;

bool checkValid(string theLine){
  vector<string> container;
  for(int i = 0; (unsigned) i < theLine.size(); i++){
    if(container.peek() == '(' && theLine[i] == ')'){
      container.pop();
    }else{
      container.push_back(theLine[i]);
    }
  }
  if(container.size() == 0){
    return true;
  }
  return false;
}

int main(){
  string line;
  vector<string> theString;
  cin>>line;
  if(line.size()%2 != 0){
    cout<<"impossible"<<endl;
  }
  for(int i = 0 ;(unsigned) i < line.size(); i++){
    if (line[i] == ')'){
      theString.pop_front();
    }else{
        theString.push_back(line[i]);
    }
  }
}
