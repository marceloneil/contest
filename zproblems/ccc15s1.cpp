//https://dmoj.ca/problem/ccc15s1
//SO PISSED AT THIS QUESTION
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int k;
  cin>>k;
  std::vector<int> arr;
  for (int i = 0 ; i < k;i++){
    int input;
    cin>>input;
    if(input == 0){
      if(arr.size() > 0){
        arr.pop_back();
      }
    }else{
      arr.push_back(input);
    }
  }
  int sum = 0;
  while(arr.size() > 0){
    sum = sum + arr.back();
    arr.pop_back();
  }
  cout<<sum<<endl;
}
