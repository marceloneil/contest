#include <iostream>
#include <cstring> //memset
#include <queue> //priority_queue
#include <vector> //vector
#include <sstream>
using namespace std;

int main(){
  string line;

  while (getline(cin, line)) {
    if(line == "0"){
      break;
    }
    vector<int> ints;

    stringstream ssin(line);
    int i = 0;
    while (ssin.good() && i < 4){
        ssin >> ints[i];
        ++i;
    }
    
  }
}
