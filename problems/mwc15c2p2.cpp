#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
  int num;
  cin>>num;
  vector<int> v(num);
  for ( int i=0; i<num; ++i ){
    cin>>v[i];
  }
  string answer = "";
  for(int i = 0 ;i < v.size();i++){
    int c = 0;
    if(i == 0){
      answer = answer + "0 ";
    }
    for(int a = i; a > 0; a--){
      if(a == 1){
        if(v[a] <= v[i]){
          c++;
          answer = answer + to_string(c) + " ";
        }else{
          answer = answer + to_string(c) + " ";
        }
      }
      if(v[a] > v[i]){
        answer = answer + to_string(c) + " ";
        a = 0;
      }else{
        c++;
      }
    }
  }
  cout<<answer<<endl;
}
