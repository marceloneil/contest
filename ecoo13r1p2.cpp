#include <iostream>
using namespace std;
int main(){
  for(int i = 0 ; i < 5;i++){
    string currString = "";
    for(int a = 0; a < 5; a++){
      int tot = 0;
      string base;
      cin>>base;
      for(int i = base.length()-1; i >=0 ;i = i-2){
        string ans = "";
        int ttot = 0;
        ans = to_string((base.at(i) - 48)*2);
        for(int i = 0; (unsigned)i < ans.size();i++){
          ttot += (ans.at(i) - 48);
        }
        tot += ttot;
      }
      for(int i = base.length()-2; i >=0 ;i = i-2){
        tot += (base.at(i) - 48);
      }
      int sol = 10 - (tot%10);
      if(tot%10 == 0){
        sol = 0;
      }
      currString += to_string(sol);
    }
    cout<<currString<<endl;
  }
}
