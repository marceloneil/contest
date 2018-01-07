#include <iostream>
#include <string>

using namespace std;

/*int findLarger(string a, string b){
  //1 = a, 2 = b, 3 = equal
}*/

int aIsLarger(string a, string b){//0 = b is larger, 1 == a is larger, 2 = they are the same
  if ((int)a.at(a.length()-1) > (int)b.at(b.length()-1)){
    return 1;
  }else if(a.at(a.length()-1) == b.at(b.length()-1) && a.length() == 1 and b.length() == b){

  }else if(a.at(a.length()-1) == b.at(b.length()-1){
    return aIsLarger(a.substr(0,a.length -2), b.substr(0,b.length -2));
  }else{
    return 0;
  }
}

string addAt(string a, string b){
  string tempAns = (string)(((int)a.at(a.length()-1)) + ((int)b.at(b.length()-1)));
  if(tempAns.size() > 1 && b.length() == 1 && a.length() == 1){
    return tempAns;
  }else if(tempAns.size() > 1 && b.length() == 1){
    return addAt(a.substr(0, a.length()-2), (string)tempAns.at(0))+ (string)tempAns.at(1);
  }else if(tempAns.size() > 1){
    string addedB = addAt(b.substr(0,b.length-2), (string)tempAns.at(0));//carry 1
    return addAt(a.substr(0, a.length()-2), addedB, i+1)+(string)tempAns.at(1);
  }else{
    if(b.length() == 1){
      return a.substr(0, a.length()-2) + tempAns;
    }else{
      return addAt(a.substr(0, a.length()-2), b.substr(0,b.length-2))+tempAns;
    }
  }
}

string subtractAt(string a, string b){
  //a is larger
  string tempAns = (string)(((int)a.at(a.length()-1)) - ((int)b.at(b.length()-1)));
  if(tempAns.size() == 2){// the answer is a negative answer

  }else{
    return addAt(a.substr(0, a.length()-2), b.substr(0,b.length-2))+tempAns;
  }
}

/*string addition(string a, string b){
  // a is larger
  string ans = "";
  for(int i = 1; (unsigned)i < b.length() + 1; i++){
    string tempAns = (string)(((int)a.at(a.length() - i)) + ((int)b.at(b.length() - i)));
    if(tempAns.size() > 1){

    }
  }
  return ans;
}*/

string subtraction(string a, string b){
  //a is larger
  string ans = "";
  int pointera = a.length()-1;
  int pointerb = b.length()-1;
  if pointerb
  if b.substr(pointerb-1,pointerb)
}

int main() {
    string a,b;
    cin>>a>>b;

    theLargerStr = "";
    theSmallerStr = "";
    //code to find the larger string
    if(a.at(0) == '-' && b.at(0) == '-'){

    }else if(a.at(0) == '-'){
      theLargerStr = b;
      theSmallerStr = a;
    }else if(b.at(0) == '-'){
      theLargerStr = a;
      theSmallerStr = b;
    }else{

    }

    //code to take the larger string and do addition with it

}
