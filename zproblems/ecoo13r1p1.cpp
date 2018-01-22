#include <iostream>
using namespace std;
int num, numS,line;
void checkMax(){
  if(num >999){
    num =1;
  }
}
int main(){
  string curr;
  cin>>curr;
  num = stoi(curr);
  cin>>curr;
  while(curr != "EOF"){
    if(curr == "TAKE"){
      num++;
      numS++;
      line++;
      checkMax();
    }else if(curr == "SERVE"){
      line--;
    }else{
      checkMax();
      cout<<to_string(numS)+" "+to_string(line)+" "+to_string(num)<<endl;
      line = 0;
      numS = 0;
    }
    cin>>curr;
  }
}
