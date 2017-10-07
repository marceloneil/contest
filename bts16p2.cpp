#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
  vector<bool> b;
  int c;
  cin>>c;
  for(int i = 0; i < c; i++){
    int a;
    bool d;
    cin>>a>>d;
    if(a == 4){
      for (int i = 0 ; i < b.size(); i++) {
        cout<<b[i]<<endl;
      }
    }else{
      if(a == 1){
        if(b.count(d) == 0){//doesn't exist
          b.insert(d);
          cout<<"true"<<endl;
        }else{
          cout<<"false"<<endl;
        }
      }else if(a == 2){
        if(b.count(d) != 0){//it exist
          b.erase(d);
          cout<<"true"<<endl;
        }else{
          cout<<"false"<<endl;
        }
      }else if(a == 3){
        bool found = false;
        for (int i = 0 ; i < b.size(); i++) {
          if(b[i] == d){
            cout<<i<<endl;
          }else{
            cout<<"-1"<<endl;
          }
        }
      }
    }
  }
}
