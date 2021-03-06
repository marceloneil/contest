#include <string>
#include <sstream>
#include <vector>
#include <iterator>

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

//note that the delimiter is a char
vector<string> split(const string &s, char delim){
  vector<string> elems;
  split(s,delim,back_inserter(elems));
  return elems;
}
