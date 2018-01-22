#include <iostream>
using namespace std;
int n,q,a,b;
string arr[100003];
int main(){
cin>>n>>q;
  for(int i = 0; i < n;i++){
    char var;
    cin>>var;
    arr[i] = var;
    if(var == '|'){
      a+=1;
    }else{
      b+=1;
    }
  }
  for(int i = 0;i<q;i++){
    int temp;
    cin>>temp;
    temp -=1;
    if(arr[temp] == "|"){
      a-=1;
      b+=1;
      arr[temp] = "-";
    }else{
      a+=1;
      b-=1;
      arr[temp] = "|";
    }
    if(arr[0] == "|"){
      cout<<1<<endl;
    }else{
      cout<<b + a*3<<endl;
    }
  }
}
