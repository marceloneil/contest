#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int t, n;
  map<string,int> m;
  cin>>t;
  for(int i = 0 ; i < t; i++){
    string word;
    cin>>word;
    m[word] = i;
  }
  cin>>n;
  pair<int,string> arr[n];
  for(int i = 0 ; i < n; i++){
    string val;
    cin>>val;
    arr[i] = make_pair(int map[val],string val);
  }
  vector<pair<int,string>> queueArr[n];
  for(int j = 0; j < t; j++){
    for(int i = 0; i < n;i++){
      if(arr[i].first == j){
        queueArr.push_back(arr[i]);
      }
    }
  }
  for(int i = 0 ; i < n; i++){
    cout<<queueArr<<endl;
  }
}
