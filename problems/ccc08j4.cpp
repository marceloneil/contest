#include <iostream>


#include <string>//split
#include <sstream>//split
#include <vector>//split
#include <iterator>//split
using namespace std;

template<typename Out>
void split(const string &s, char delim, Out result){
  stringstream ss;
  ss.str(s);
  string item;
  while(getline(ss,item,delim)){
    *(result++) = item;
  }
}

vector<string> split(const string &s, char delim){
  vector<string> elems;
  split(s,delim,back_inserter(elems));
  return elems;
}

int main(){
  string line;
  cin>>line;
  while(line != "0"){
    vector<string> equation = split(line,' ');
    vector<string> output;
    for(int i = equation.size()-1; i == 0; i--){
      if(equation[i] == "+" || equation[i] == "-"){
        output.push_back(equation[i+1]);
        output.push_back(equation[i+2]);
        output.push_back(equation[i]);
      }
    }
    string rebuildString;
    for(int i = 0;(unsigned)i< equation.size();i++){
      if(i == 0){
        rebuildString = equation[i];
      }else{
        rebuildString = rebuildString + " " + equation[i];
      }
    }
    cout<<rebuildString<<endl;
    cin>>line;
  }
}
